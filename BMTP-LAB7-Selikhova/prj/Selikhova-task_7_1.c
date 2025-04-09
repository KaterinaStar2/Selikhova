#include <stdio.h>
#include <string.h>
void swap_pairs(char *s) {
    for (int i = 0; s[i] != '\0' && s[i + 1] != '\0'; i += 2) {
        char temp = s[i];
        s[i] = s[i + 1];
        s[i + 1] = temp;
    }
}
int count_syllable(const char *s, const char *syllable) {
    int count = 0;
    const char *ptr = strstr(s, syllable);
    while (ptr) {
        count++;
        ptr = strstr(ptr + 1, syllable);
    }
    return count;
}
int main() {
    char word[101]; // Припустимо, що максимальна довжина слова — 100 символів
    printf("Введіть слово, що закінчується на '!': ");
    scanf("%100s", word);
    int len = strlen(word);
    if (len < 7 || word[len - 1] != '!') {
        printf("Некоректне введення! Слово має містити не менше 6 літер і закінчуватися '!'\n");
        return 1;
    }
    word[len - 1] = '\0'; // Видаляємо "!"
    int count = count_syllable(word, "ко");
    if (count > 0) {
        printf("%d\n", count);
    } else {
        swap_pairs(word);
        printf("%s\n", word);
    }
    return 0;
}
