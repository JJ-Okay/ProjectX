
#include <cstdio>
#include <cstring>

const bool male = false;
const bool female = true;

struct employee
{
    char second_name[255];
    char first_name[255];
    bool gender;
    employee *next;// указатель на структуру типа employee
    employee *prev;//указатель на предыдущий элемент
    int wages;
    char profession [255];
    char date [255];
    
};

bool god(employee* &first, employee* &last)
{
    
    employee* new_element = new employee;
    printf("Employee names: \n");
    scanf(" %255s", new_element->first_name);
    scanf(" %255s", new_element->second_name);
    printf("Employee gender(m or w): \n");
    char gender;
    scanf(" %c", &gender);
    if (gender == 'w')
        new_element->gender = female;
    else if (gender == 'm')
        new_element -> gender = male;
    else
        return false;
   
    printf("Profession: ");
    scanf ("%255s", new_element -> profession);
    printf("Enter wages: ");
    scanf("%d", & new_element -> wages);
    printf("Date: ");
    scanf("%255s", new_element -> date);
    

    new_element -> next = NULL;// отчистка поля указателя на следующего студента
    new_element -> prev = NULL;
    if (first==NULL) // проверка создания список
    {
        first = new_element;
        last = first;
    }
    else
    {
        last -> next = new_element;
        new_element -> prev = last;
        last = new_element;
    }
    
    
    return true;
}
void printb(employee* B)
{
    
    printf("%s ", B->profession);
    printf("%d\n", B -> wages);
    printf("%s ", B->date);
   
}
void print(employee* new_element)
{
    printf("%s %s\n", new_element->first_name, new_element->second_name);
    if (new_element->gender == female)
        printf("female\n");
    else
        printf("male\n");
    printf("Profession: %s\n", new_element -> profession);
    printf("Wages: %d\n", new_element -> wages);
    printf("Date: %s\n", new_element -> date);
}
void print_list(employee* F)
{
    for(employee* C = F; C; C = C -> next)
    {
        print(C);
    }
}

void deleteit(employee* first)
{
    employee* next;
    do
    {
        next= first -> next;
        delete first;
        first = next;
    } while (next != NULL);
    
}
int counter(employee* first)
{
    int i=0;
    for(employee*C = first; C; C = C-> next)
    {
        i ++;
    }
    return i;
}
void swap_neighbour (employee* one, employee* another)
{
    employee* temp = one;
    if ( one->next != another)
    {
        one =  another;
        another = temp;
        
    }
    if ( one->prev != NULL)
        one->prev->next = another;
    if ( another->next != NULL)
	another->next->prev = one;

    temp = one->prev;
    one->prev = another;
    one->next = another->next;

    another->next = one;
    another->prev = temp;

}
int sort_list(employee*& first)
{
    bool sorted = false;
    while (!sorted)
    {
    sorted = true;
    for(employee* cur = first->next; cur; cur = cur->next)
    {
	    int first_cmp = strcmp(cur->first_name, cur->prev->first_name);
	    int second_cmp = strcmp(cur->second_name, cur->prev->second_name);
	    if (first_cmp < 0 || (first_cmp == 0 && second_cmp < 0))
	    {
		    if (cur->prev->prev == NULL)
			    first = cur;
		    swap_neighbour(cur->prev, cur);
		    cur = cur->next;
		    sorted = false;
	    }
    }
    }
}



int main()
{
    employee* first = NULL;
    employee* last = NULL;
    while (god(first, last))
    {
        
        printf("would you like to continue?(y/n) \n");
        char answer;
        scanf(" %c", &answer);
        if(answer!='y')
            break;
    }
    sort_list(first);
    print_list(first);
    deleteit(first);
    return 0;
}
