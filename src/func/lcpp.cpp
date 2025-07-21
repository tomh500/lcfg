#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <filesystem>
#include <iomanip>

namespace lcpp {

// 动态计算缩放比例：1 / (sensitivity * m_axis)
double getScale(double sensitivity, double m_axis) {
    return 1.0 / (sensitivity * m_axis);
}

void parseFile(const std::string& inputPath,
               std::vector<double>& yawVals,
               std::vector<double>& pitchVals,
               int& maxIndex) {
    std::ifstream inFile(inputPath);
    if (!inFile) {
        throw std::runtime_error("Failed to open input file: " + inputPath);
    }

    std::string line;
    std::regex yawRegex(R"(^\s*yaw\[(\d+)\]\s*=\s*([-0-9\.]+);)");
    std::regex pitchRegex(R"(^\s*pitch\[(\d+)\]\s*=\s*([-0-9\.]+);)");
    yawVals.clear();  pitchVals.clear();
    yawVals.resize(1);
    pitchVals.resize(1);
    maxIndex = 0;

    while (std::getline(inFile, line)) {
        std::smatch m;
        if (std::regex_search(line, m, yawRegex)) {
            int idx = std::stoi(m[1].str());
            double v = std::stod(m[2].str());
            if (yawVals.size() <= static_cast<size_t>(idx))
                yawVals.resize(idx + 1);
            yawVals[idx] = v;
            maxIndex = std::max(maxIndex, idx);
        } else if (std::regex_search(line, m, pitchRegex)) {
            int idx = std::stoi(m[1].str());
            double v = std::stod(m[2].str());
            if (pitchVals.size() <= static_cast<size_t>(idx))
                pitchVals.resize(idx + 1);
            pitchVals[idx] = v;
            maxIndex = std::max(maxIndex, idx);
        }
    }
}

void writeOutput(const std::filesystem::path& outFile,
                 const std::vector<double>& yawVals,
                 const std::vector<double>& pitchVals,
                 int maxIndex,
                 double yawScale,
                 double pitchScale) {
    std::ofstream ofs(outFile, std::ios::binary);
    if (!ofs) {
        throw std::runtime_error("Failed to create output file: " + outFile.string());
    }

    ofs << "alias PressRecoil_Angle PressRecoil_Angle1\n";
    for (int i = 1; i <= maxIndex; ++i) {
        double yy = yawVals[i] * yawScale;
        double pp = pitchVals[i] * pitchScale;
        std::ostringstream ss;
        ss << std::fixed << std::setprecision(9);
        ss << "alias PressRecoil_Angle" << i
           << " \"yaw " << yy << " 1 1; pitch " << pp
           << " 1 1;alias PressRecoil_Angle "
           << (i < maxIndex ? ("PressRecoil_Angle" + std::to_string(i + 1)) : "")
           << "\"\n";
        ofs << ss.str();
    }
}

int run(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    try {
        std::string inputPath = argv[1];
        std::filesystem::path inPath(inputPath);
        std::string baseName = inPath.stem().string();
        std::filesystem::path outDir = std::filesystem::current_path() / baseName;
        std::filesystem::create_directories(outDir);

        // 获取用户输入
        double sensitivity, m_yaw, m_pitch;
        std::cout << "请输入 sensitivity: "; std::cin >> sensitivity;
        std::cout << "请输入 m_yaw: ";    std::cin >> m_yaw;
        std::cout << "请输入 m_pitch: ";  std::cin >> m_pitch;

        // 计算缩放比例
        double yawScale = getScale(sensitivity, m_yaw);
        double pitchScale = getScale(sensitivity, m_pitch);

        // 解析输入
        std::vector<double> yawVals, pitchVals;
        int maxIndex = 0;
        parseFile(inputPath, yawVals, pitchVals, maxIndex);

        // 写入输出
        std::filesystem::path outFile = outDir / "AngelData.cfg";
        writeOutput(outFile, yawVals, pitchVals, maxIndex, yawScale, pitchScale);

        std::cout << "Generated: " << outFile << std::endl;
        return 0;
    } catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
}

} // namespace lcpp