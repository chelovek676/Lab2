struct stroika{
char name[40];
char color[40];
char whomade[40]; 
int price;
};
void write(struct stroika *arr, int n);
void read(struct stroika **arr, int *n);
void create(struct stroika **arr, int *n);
void find(struct stroika *arr, int n);

