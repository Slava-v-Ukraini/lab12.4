#include "pch.h"
#include "CppUnitTest.h"
#include "../PR12.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TrainAppTests
{
    TEST_CLASS(TrainAppTests)
    {
    public:

        TEST_METHOD(AddTrainTest)
        {
            // Ім'я тестового файлу
            const string testFilename = "test_trains.dat";

            // Створення та додавання тестового запису
            Train testTrain = { "Тестовий пункт", EXPRESS, "12:00" };

            ofstream testFile(testFilename, ios::binary);
            testFile.write((char*)&testTrain, sizeof(Train));
            testFile.close();

            // Читання з файлу для перевірки
            ifstream inFile(testFilename, ios::binary);
            Train readTrain;
            inFile.read((char*)&readTrain, sizeof(Train));
            inFile.close();

            // Перевірки
            Assert::AreEqual(string(testTrain.destination), string(readTrain.destination));
            Assert::AreEqual((int)testTrain.type, (int)readTrain.type);
            Assert::AreEqual(string(testTrain.departureTime), string(readTrain.departureTime));

            // Видалення тестового файлу
            remove(testFilename.c_str());
        }
    };
}
