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
            // ��'� ��������� �����
            const string testFilename = "test_trains.dat";

            // ��������� �� ��������� ��������� ������
            Train testTrain = { "�������� �����", EXPRESS, "12:00" };

            ofstream testFile(testFilename, ios::binary);
            testFile.write((char*)&testTrain, sizeof(Train));
            testFile.close();

            // ������� � ����� ��� ��������
            ifstream inFile(testFilename, ios::binary);
            Train readTrain;
            inFile.read((char*)&readTrain, sizeof(Train));
            inFile.close();

            // ��������
            Assert::AreEqual(string(testTrain.destination), string(readTrain.destination));
            Assert::AreEqual((int)testTrain.type, (int)readTrain.type);
            Assert::AreEqual(string(testTrain.departureTime), string(readTrain.departureTime));

            // ��������� ��������� �����
            remove(testFilename.c_str());
        }
    };
}
