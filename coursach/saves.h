#include <iostream> // ���������� ���������� ��� ������ � ������-�������
#include <fstream> // ���������� ���������� ��� ������ � �������
#include <vector> // ���������� ���������� ��� ������ � ���������
#include <map> // ���������� ���������� ��� ������ � �������������� ���������
#include <string> // ���������� ���������� ��� ������ �� ��������

typedef std::vector<std::map<std::string, std::string>> SaveType; // ���������� ��� ������ ��� ����������

class CONFIG { // ����� ��� ������ � �������������
private:
    int language_ = 0; // ���������� ��� �������� �����
    int style_ = 0; // ���������� ��� �������� �����
    std::string refreshToken_; // ���������� ��� �������� ������������ ������
    std::string Token_; // ���������� ��� �������� ������
    SaveType saves_; // ���������� ��� �������� ����������

public:
    CONFIG() = default; // ����������� �� ���������

    void changeStyle() { // ����� ��� ��������� �����
        style_ = (style_ + 1) % 3;
    }

    void changeLanguage() { // ����� ��� ��������� �����
        language_ = (language_ + 1) % 3;
    }

    int getLanguage() const { // ����� ��� ��������� �����
        return language_;
    }

    int getStyle() const { // ����� ��� ��������� �����
        return style_;
    }

    void addSave(std::map<std::string, std::string> newSave) { // ����� ��� ���������� ����������
        saves_.push_back(newSave);
        if (saves_.size() > 20)
            saves_.erase(saves_.begin());
    }

    const SaveType& getSaves() const { // ����� ��� ��������� ����������
        return saves_;
    }

    void saveToFile(const std::string& fileName = "settings.bin") { // ����� ��� ���������� � ����
        std::ofstream file(fileName, std::ios::binary); // ��������� ���� ��� ������
        if (file.is_open()) { // ���� ���� ������
            file.write(reinterpret_cast<const char*>(&language_), sizeof(language_)); // ���������� ����
            file.write(reinterpret_cast<const char*>(&style_), sizeof(style_)); // ���������� �����
            file.write(Token_.c_str(), Token_.size()); // ���������� �����
            file.write(refreshToken_.c_str(), refreshToken_.size()); // ���������� ����������� �����
            // ��������� ������ �������
            size_t size = saves_.size();
            file.write(reinterpret_cast<const char*>(&size), sizeof(size));
            // ��������� ������ ����� � �������
            for (const auto& save : saves_) {
                size_t mapSize = save.size();
                file.write(reinterpret_cast<const char*>(&mapSize), sizeof(mapSize));
                for (const auto& pair : save) {
                    size_t keySize = pair.first.size();
                    file.write(reinterpret_cast<const char*>(&keySize), sizeof(keySize));
                    file.write(pair.first.c_str(), pair.first.size());
                    size_t valueSize = pair.second.size();
                    file.write(reinterpret_cast<const char*>(&valueSize), sizeof(valueSize));
                    file.write(pair.second.c_str(), pair.second.size());
                }
            }
            file.close(); // ��������� ����
        }
    }

    void readFromFile(const std::string& fileName = "settings.bin") { // ����� ��� ������ �� �����
        std::ifstream file(fileName, std::ios::binary); // ��������� ���� ��� ������
        if (file.is_open()) { // ���� ���� ������
            file.read(reinterpret_cast<char*>(&language_), sizeof(language_)); // ������ ����
            file.read(reinterpret_cast<char*>(&style_), sizeof(style_)); // ������ �����
            file.read(&Token_[0], Token_.size()); // ������ �����
            file.read(&refreshToken_[0], refreshToken_.size()); // ������ ����������� �����
            // ������ ������ �������
            size_t size;
            file.read(reinterpret_cast<char*>(&size), sizeof(size));
            // ������ ������ ����� � �������
            for (size_t i = 0; i < size; ++i) {
                std::map<std::string, std::string> save;
                size_t mapSize;
                file.read(reinterpret_cast<char*>(&mapSize), sizeof(mapSize));
                for (size_t j = 0; j < mapSize; ++j) {
                    size_t keySize;
                    file.read(reinterpret_cast<char*>(&keySize), sizeof(keySize));
                    std::string key(keySize, ' ');
                    file.read(&key[0], keySize);
                    size_t valueSize;
                    file.read(reinterpret_cast<char*>(&valueSize), sizeof(valueSize));
                    std::string value(valueSize, ' ');
                    file.read(&value[0], valueSize);
                    save[key] = value;
                }
                saves_.push_back(save);
            }
            file.close(); // ��������� ����
        }
    }
};
