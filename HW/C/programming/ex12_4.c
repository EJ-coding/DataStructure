void diff_array(int arr[], int first, int diff, int size)
{
    arr[0] = first;
    for(int i = 1 ; i< size; i++)
    {
        arr[i] =first +diff*i;

    }
    
}
//100점부터 90점까지 A, 89점부터 80점까지 B, 79점부터 70점까지 C, 
//69점부터 60점까지 D, 60점 미만은 F 학점으로 
void grade_array(int score[], char grade[], int size)
{
    for(int i =0; i<size; i++){

        switch(score[i]/10){
            case 10:
            case 9:
                grade[i] = 'A';
                break;
            case 8:
                grade[i] = 'B';
                break;
            case 7:
                grade[i] = 'C';
                break;
            case 6:
                grade[i] = 'D';
                break;
            default:
                grade[i] = 'F';

        }
    }
}
int main(){
    int arr[10];
    diff_array(arr,1,2,10);
    for(int i =0 ;i<10;i++){
        printf("%d ",arr[i]);
    }
    int score[] = {10,20,60,55,70,80,90,52,90,100};
    char grade[10];
    grade_array(score,grade,10);
    for(int i = 0; i<10; i++){
        printf("%c",grade[i]);
    }
}