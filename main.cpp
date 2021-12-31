#include <iostream>
#include <iomanip>
#include <vector>

int main() {
    system("chcp 65001");

    int n;
    long double m, sum = 0;

    std::cout << "Введите количество элементов попарного сравнения для расчёта коэфициентов метода анализа иерархий Томаса Саати: ";
    std::cin >> n;
    if (n <= 0) std::cout << "Вы ввели некорректное значение !";

    std::vector < std::vector <long double> > a (n, std::vector <long double> (n + 2) );


    std::string *names = new std::string [n];

    for (int i = 0; i < n; ++i) {
        std::cout << "Введите название критерия №" << i + 1 << ": ";
        std::cin >> names[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                if (a[i][j] == 0){
                    std::cout << std::endl << "На сколько по вашему мнению параметр -" << names[i] << "- важнее параметра -" << names[j] << "-" << std::endl << std::endl;
                    std::cout << "Подсказка:" << std::endl << "1 - равная важность" << std::endl
                              << "3 - умеренное превосходство одного над другим" << std::endl
                              << "5 - существенное превосходство одного над другим" << std::endl
                              << "7 - значительное превосходство одного над другим" << std::endl
                              << "9 - очень сильное превосходство одного над другим" << std::endl
                              << "2,4,6,8 - соответствующие промежуточные значения" << std::endl << std::endl;
                    std::cout << "Введите число от 1 до 9 (Если вы хотите пропустить данный пункт и ввести важность для обратного паросочетания - введите 0): ";
                    std::cin >> m;


                    if (m >= 1 && m <= 9){
                        a[i][j] = m;
                        a[j][i] = 1 / m;
                    }

                }
            } else {
                a[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][n] += a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        sum += a[i][n];
    }

    for (int i = 0; i < n; ++i) {
        a[i][n + 1] = a[i][n] / sum;
    }

    std::cout << std::endl << std::endl << "Ваши итоговы коэффициенты для параметров:" << std::endl << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << names[i] << " = ";
        std::cout << std::fixed << std::setprecision(2) << a[i][n + 1] << std::endl;
    }

    std::cout << std::endl << "Благодарим вас за использование программы для расчёта коэфициентов метода анализа иерархий Томаса Саати ";

    system("pause");

}
