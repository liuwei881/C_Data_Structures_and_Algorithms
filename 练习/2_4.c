#include <stdio.h>
#include <string.h>

//void squeeze2();
//
//int main(){
//    char s1[]="abcdef";
//    char s2[]="acferx";
//    squeeze2(s1[10], s2[10]);
//    squeeze2("abcdef", "acferx");
//    return 0;
//}
//
//void squeeze2(char s1[], char s2[]){
//    int i=0;
//    int j=0;
//    for(i=0; s1[i]!='\0'; i++){
//        for(j=0; s2[j]!='\0'; j++){
//            if(s1[i]==s2[j]){
//                s1[j++] = s1[i];
//                printf("%c", s1[i]);
//            }
//        }
//    }
//    for(i; i<strlen(s1); i++){
//        printf("%c,", s1[i]);
//    }
//    printf("\n");
//}

void squeeze2(char s1[], char s2[])
{
    int i, j, k;
    int instr2 = 0;
    for(i = j = 0; s1[i] != '\0'; i++)
    {
        instr2 = 0;
        for(k = 0; s2[k] != '\0' && !instr2; k++)
        {
            if(s2[k] == s1[i])
            {
                instr2 = 1;
            }
        }
        if(!instr2)
        {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

int main(void)
{
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
            "xylophonically", /* if there is such a word :-) */
            "youthfulness",
            "zoologically"
            };
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
                    "linux"
            };
    char buffer[32];
    size_t numlefts = sizeof leftstr / sizeof leftstr[0];
    size_t numrights = sizeof rightstr / sizeof rightstr[0];
    size_t left = 0;
    size_t right = 0;
    for(left = 0; left < numlefts; left++)
    {
        for(right = 0; right < numrights; right++)
        {
            strcpy(buffer, leftstr[left]);
            squeeze2(buffer, rightstr[right]);
            printf("[%s] - [%s] = [%s]\n", leftstr[left], rightstr[right], buffer);
        }
    }
    return 0;
}


