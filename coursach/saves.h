#include <iostream> // подключаем библиотеку для работы с вводом-выводом
#include <fstream> // подключаем библиотеку для работы с файлами
#include <vector> // подключаем библиотеку для работы с векторами
#include <map> // подключаем библиотеку для работы с ассоциативными массивами
#include <string> // подключаем библиотеку для работы со строками

typedef std::vector<std::map<std::string, std::string>> SaveType; // определяем тип данных для сохранения

class CONFIG { // класс для работы с конфигурацией
private:
    int language_ = 0; // переменная для хранения языка
    int style_ = 0; // переменная для хранения стиля
    std::string refreshToken_; // переменная для хранения обновленного токена
    std::string Token_; // переменная для хранения токена
    SaveType saves_; // переменная для хранения сохранений

public:
    CONFIG() = default; // конструктор по умолчанию

    void changeStyle() { // метод для изменения стиля
        style_ = (style_ + 1) % 3;
    }

    void changeLanguage() { // метод для изменения языка
        language_ = (language_ + 1) % 3;
    }

    int getLanguage() const { // метод для получения языка
        return language_;
    }

    int getStyle() const { // метод для получения стиля
        return style_;
    }

    void addSave(std::map<std::string, std::string> newSave) { // метод для добавления сохранения
        saves_.push_back(newSave);
        if (saves_.size() > 20)
            saves_.erase(saves_.begin());
    }

    const SaveType& getSaves() const { // метод для получения сохранений
        return saves_;
    }

    void saveToFile(const std::string& fileName = "settings.bin") { // метод для сохранения в файл
        std::ofstream file(fileName, std::ios::binary); // открываем файл для записи
        if (file.is_open()) { // если файл открыт
            file.write(reinterpret_cast<const char*>(&language_), sizeof(language_)); // записываем язык
            file.write(reinterpret_cast<const char*>(&style_), sizeof(style_)); // записываем стиль
            file.write(Token_.c_str(), Token_.size()); // записываем токен
            file.write(refreshToken_.c_str(), refreshToken_.size()); // записываем обновленный токен
            // Сохраняем размер вектора
            size_t size = saves_.size();
            file.write(reinterpret_cast<const char*>(&size), sizeof(size));
            // Сохраняем каждую карту в векторе
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
            file.close(); // закрываем файл
        }
    }

    void readFromFile(const std::string& fileName = "settings.bin") { // метод для чтения из файла
        std::ifstream file(fileName, std::ios::binary); // открываем файл для чтения
        if (file.is_open()) { // если файл открыт
            file.read(reinterpret_cast<char*>(&language_), sizeof(language_)); // читаем язык
            file.read(reinterpret_cast<char*>(&style_), sizeof(style_)); // читаем стиль
            file.read(&Token_[0], Token_.size()); // читаем токен
            file.read(&refreshToken_[0], refreshToken_.size()); // читаем обновленный токен
            // Читаем размер вектора
            size_t size;
            file.read(reinterpret_cast<char*>(&size), sizeof(size));
            // Читаем каждую карту в векторе
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
            file.close(); // закрываем файл
        }
    }
};
