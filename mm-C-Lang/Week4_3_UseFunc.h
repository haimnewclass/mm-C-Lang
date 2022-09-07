

struct item {
	int a;
};


typedef struct s_item {
	int key;
	int val;
	struct s_item* next;
	struct s_item* prev;

} t_Item;


typedef struct s_item2 {
	int key;
	int val;
	int id;
	struct s_item* next;
	struct s_item* prev;

} t_Item2;


typedef struct {
	int version;
	int serialNum;
	int ItemsCount;
	char date[8];
	char reserve[92];
} t_headerFile;