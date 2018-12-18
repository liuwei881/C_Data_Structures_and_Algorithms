#include <stdio.h>
#include <string.h>

//extern int any2();
//
//int main(){
//    int i;
//    i = any2("abcdef", "cdaclie");
//    printf("%d", i);
//    return 0;
//}
//
//
//int any2(char s1[10], char s2[10]){
//    int num1;
//    int num2;
//    int i;
//    int j;
//    int pos = -1;
//    num1 = strlen(s1);
//    num2 = strlen(s2);
//    for(i=0; i<num2; ++i){
//        for(j=0; j<num1; ++j){
//            if(s1[j]==s2[i]){
//                pos = j;
//            }
//        }
//    }
//    return pos;
//}

int any(char s1[], char s2[]){
    int i;
    int j;
    int pos;
    pos = -1;
    for(i = 0; pos == -1 && s1[i] != '\0'; i++){
        for(j = 0; pos == -1 && s2[j] != '\0'; j++){
            if(s2[j] == s1[i]){
                pos = i;
            }
        }
    }
    return pos;
}

int main(){
    char *leftstr[] = {
        "",
        "a",
        "antidisestablishmentarianism",
        "beautifications",
        "characteristically",
        "deterministically",
        "electroencephalography",
        "familiarisation",
        "gastrointestinal",
        "heterogeneousness",
        "incomprehensibility",
        "justifications",
        "knowledgeable",
        "lexicographically",
        "microarchitectures",
        "nondeterministically",
        "organizationally",
        "phenomenologically",
        "quantifications",
        "representationally",
        "straightforwardness",
        "telecommunications",
        "uncontrollability",
        "vulnerabilities",
        "wholeheartedly",
        "xylophonically",
        "youthfulness",
        "zoologically"};
    char *rightstr[] = {
        "",
        "a",
        "the",
        "quick",
        "brown",
        "dog",
        "jumps",
        "over",
        "lazy",
        "fox",
        "get",
        "rid",
        "of",
        "windows",
        "and",
        "install",
        "linux"};
    size_t numlefts = sizeof leftstr / sizeof leftstr[0];
    size_t numrights = sizeof rightstr / sizeof rightstr[0];
    size_t left = 0;
    size_t right = 0;
    int passed = 0;
    int failed = 0;
    int pos = -1;
    char *ptr = NULL;
    for(left = 0; left < numlefts; left++){
        for(right = 0; right < numrights; right++){
            pos = any(leftstr[left], rightstr[right]);
            ptr = strpbrk(leftstr[left], rightstr[right]);
            if(-1 == pos){
                if(ptr != NULL){
                    printf("Test %d/%d failed.\n", left, right);
                    ++failed;
                }
                else{
                    printf("Test %d/%d passed.\n", left, right);
                    ++passed;
                }
            }
            else{
                if(ptr == NULL){
                    printf("Test %d/%d failed.\n", left, right);
                    ++failed;
                }
                else{
                    if(ptr - leftstr[left] == pos){
                        printf("Test %d/%d passed.\n", left, right);
                        ++passed;
                    }
                    else{
                        printf("Test %d/%d failed.\n", left, right);
                        ++failed;
                    }
                }
            }
        }
    }
    printf("\n\nTotal passes %d, fails %d, total tests %d\n",
           passed,
           failed,
           passed + failed);
    return 0;
}