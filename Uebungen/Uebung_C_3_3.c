#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100
#define BUFSIZE 100

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};
/* siehe auch Buch K&R S. 77 */
char buf[BUFSIZE]; /* Buffer fuer ungetch() */
int bufp = 0; /* naechste freie Position für buf */

int getch(void) {
    /* naechstes Zeichen holen */ return (bufp > 0 ? buf[--bufp] : getchar());
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* siehe auch Buch K&R S. 131 */
int getword(char *word, int lim) {
    int c;
    char *w = word;
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return (c);
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);

/* Haeufigkeit von Woerter zaehlen */
main() {
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;
    printf("File wird eingelesen...\n");
    if (freopen("inputfile1.txt", "r", stdin) == NULL) {
        printf("kann File nicht öffnen\n");
    }
    while (getword(word, MAXWORD) != EOF)
        if (isalha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    return (0);
}