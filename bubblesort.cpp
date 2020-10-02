#include "bubblesort.h"

BubbleSort::BubbleSort(QObject *parent,int *arr,int val) : QObject(parent)
{
    array=arr;
    n=val;
}

bool BubbleSort::running() const
{
    return m_running;
}

void BubbleSort::run()
{
    while(m_running){
    for(int i = 1; i < n; ++i)
            for(int r = 0; r < n-i; r++){
                sortArr(r);
                if(m_running==false)
                    return;
            }
    setRunning(false); }
    emit finished();
    return;
}

void BubbleSort::sortArr(int r)
{
    if(array[r] < array[r+1]){
        int temp = array[r];
        array[r] = array[r+1];
        array[r+1] = temp;
    }
}

void BubbleSort::setRunning(bool running)
{
    if (m_running == running)
        return;

    m_running = running;
    emit runningChanged(running);
}

void BubbleSort::getArray()
{
    emit nowArray(array);
}
