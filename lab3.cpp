#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
int main()
{
    //zadanie 1
    std::srand(std::time(nullptr));
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = std::rand() % 21 - 10;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    int last = arr[9];
    for (int i = 0; i < 10; ++i) {
        double rez = arr[i] / last;
        std::cout << rez << " ";
    }
    std::cout << std::endl;
    //zadanie 2
    int n;
    std::cout << "vvedi dlinu massiva" << std::endl;
    std::cin >> n;
    int* arr2 = new int[n];
    std::cout << "vvedi massiv" << std::endl;
    for (int i = 0; i < n; ++i) std::cin >> arr2[i];
    for (int i = 0; i < n; ++i) {
        std::cout << arr2[i] << " ";
        if (arr2[i] == 0) arr2[i] += 9;
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) std::cout << arr2[i] << " ";
    std::cout << std::endl;
    std::cout << "vvedi k1 i k2" << std::endl;
    int k1, k2;
    std::cin >> k1 >> k2;
    int sum = 0;
    for (int i = k1; i <= k2; ++i) sum += arr2[i];
    std::cout << "summa ravna " << sum << std::endl;
    delete[] arr2;
    // zadanie 3
    int m=0;
    int a=0;
    std::cout << "vvedi dlinu massiva" << std::endl;
    std::cin >> m;
    std::vector<int> vec1;
    std::cout << "vvedi massiv" << std::endl;
    for (int i = 0; i < m; ++i) {
        std::cin >> a;
        vec1.insert(vec1.end(), a);
    }
    for (int i = 0; i < m; ++i) std::cout << vec1[i] << " ";
    std::cout << std::endl;
    vec1.insert(vec1.end(), 8); //8 variant
    for (int i = 0; i < vec1.size(); ++i) std::cout << vec1[i] << " ";
    std::cout << std::endl;
    sum = 0;
    for (int i = 0; i < vec1.size(); ++i) sum += vec1[i];
    std::cout << "summa vectora ravna " << sum << std::endl;
    int nomer = -1;
    for (int i = 0; i < vec1.size(); ++i) {
        if (vec1[i] == 0) {
            nomer = i;
            break;
        }
    }
    if (nomer != -1) vec1.erase(vec1.begin()+nomer);
    for (int i = 0; i < vec1.size(); ++i) std::cout << vec1[i] << " ";
    std::cout << std::endl;
    //zadanie 4
    std::cout << "vvedi stroky" << std::endl;
    std::string str1;
    std::cin.ignore(10, '\n');
    std::getline(std::cin, str1);
    std::cout << str1 << std::endl;
    int kolvo0 = 0;
    for (int i = 0; i < str1.size(); ++i)
        if (str1[i] == '0') kolvo0++;
    std::cout << "dlina stroki ravna " << str1.size() << ", dolya 0 ravna " << kolvo0 * 1.0 / str1.size() <<std::endl;
    std::cout << "vvedi l1 i l2" << std::endl;
    int l1, l2;
    std::cin >> l1 >> l2;
    std::cout << str1.substr(l1, l2 - l1 + 1) << std::endl;
    std::cout << "vvedi zameny" << std::endl;
    std::string str2 = "Can you can a can as a canner can can a can";
    std::string str3;
    std::cin.ignore(10, '\n');
    std::getline(std::cin, str3);
    std::string strc = "can";
    while (str2.find(strc) != std::string::npos) {
        auto pos = str2.find(strc);
        str2.erase(pos, strc.size());
        str2.insert(pos, str3);
    }
    strc = "Can";
    if ((str3[0] >= 97) && (str3[0] <= 122)) str3[0] -= 32; // делаем букву заглавной тк она будет в начале предложения
    while (str2.find(strc) != std::string::npos) {
        auto pos = str2.find(strc);
        str2.erase(pos, strc.size());
        str2.insert(pos, str3);
    }
    std::cout << str2;
    return 0;
}


