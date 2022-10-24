/*arg:
-sorting
-files
-ricorsive
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class Sorter{
    private:
        int box,i,j;
    public:
        Sorter(){
            box = 0;
            i = 0;
            j = 0;
        }
        ~Sorter(){
            free(&box);
            free(&i);
            free(&j);
        }
        void bubbleSort(int *array, int size){
            for(i = 0; i < size; i++){
                for(j = 0; j < size - 1; j++){
                    if(array[j] > array[j + 1]){
                        box = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = box;
                    }
                }
            }
        }
        void selectionSort(int *array, int size){
            for(i=0; i<(size-1); i++){
                for(j=(i+1); j<size; j++){
                    if(array[i] > array[j]){
                        box = array[i];
                        array[i] = array[j];
                        array[j] = box;
                    }
                }
            }
        }
        void insertionSort(int *array, int size){
            for(i=1; i<size; i++){
                box = array[i];
                j = i-1;
                while(j>=0 && array[j]>box){
                    array[j+1] = array[j];
                    j--;
                }
                array[j+1] = box;
            }
        }
};

int main(){
    int array[10] = {2,4,3,1,5,6,9,7,8,10};
    char *str = new char[10];
    Sorter sorter = Sorter();
    sorter.bubbleSort(array,10);
    FILE* in = fopen("input.txt","r");
    FILE* out = fopen("output.txt","w");

    fscanf(in,"%d",&array[0]);
    fprintf(out,"%d",array[0]);
    fgets(str,10,in);
    fread(str,10,4,in);
    fgetc(in);
    fseek(in,0,SEEK_END);
    ftell(in);
    fclose(in);
    fclose(out);

    for(int i=0; i<10; i++){
        cout << array[i] << " ";
    }

    return 0;
}