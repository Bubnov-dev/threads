#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <QObject>
#include<QDebug>

class BubbleSort : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)
public:
    explicit BubbleSort(QObject *parent = nullptr,int *arr=nullptr,int val=0);
    /**
     * @brief running Возврат проверки выполнения сортировки
     * @return Проверка для выполнения сортировки
     */
    bool running() const;
    /**
     * @brief sortArr Сортировка пузырьком
     */
    void sortArr(int);

public slots:
    /**
     * @brief run Выполнение сортировки
     */
    void run();
    /**
     * @brief setRunning Установка проверки выполнения сортировки
     * @param running Проверка для выполнения сортировки
     */
    void setRunning(bool running);
    /**
     * @brief getMassiv Получение массива
     */
    void getArray();

private:
    int *array;
    int n;
    bool m_running;


signals:
    /**
     * @brief nowMassiv Сигнал для передачи массива
     */
    void nowArray(int*);
    /**
     * @brief finished Окончание сортировки
     */
    void finished();
    /**
     * @brief runningChanged Сигнал смены значения у проверки для выполнения сортировки
     * @param running  Проверка для выполнения сортировки
     */
    void runningChanged(bool running);

};

#endif // BUBBLESORT_H
