#include <stdio.h>
#define SIZE 30
void swap_halves(double arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        double temp = arr[i];
        arr[i] = arr[i + size / 2];
        arr[i + size / 2] = temp;
    }
}
double find_min(double arr[], int size) {
    double min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
double find_max(double arr[], int size) {
    double max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
double positive_avg(double arr[], int size) {
    double sum = 0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
            count++;
        }
    }
    return count > 0 ? sum / count : 0; // ������� ������ �� ����
}
void print_array(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}
int main() {
    double array[SIZE];
    // �������� ������
    printf("������ 30 ������ �����:\n");
    for (int i = 0; i < SIZE; i++) {
        scanf("%lf", &array[i]);
    }
    // ����������� ����������, ������������� �������� �� ���������� ������������� ��������
    double min = find_min(array, SIZE);
    double max = find_max(array, SIZE);
    double avg = positive_avg(array, SIZE);
    // ���� ����������
    printf("��������� �������: %.2f\n", min);
    printf("��������� �������: %.2f\n", max);
    printf("������ ����������� �������� ��������: %.2f\n", avg);

    // ���� ���� ������� ������
    swap_halves(array, SIZE);
    printf("����� ���� ����� �������:\n");
    print_array(array, SIZE);
    return 0;
}