#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct Task {
std::string description;
bool completed;

    Task(std::string desc,bool comp) : description (desc), completed(comp) {}
};
void addTask(std::vector<Task>& tasks) {
    std::string desc;
    std::cin.ignore(); 
    std::cout<<"Enter Task description: ";
    std::getline(std::cin,desc);
    tasks.push_back(Task(desc, false));
}
void viewTask(const std::vector<Task>& tasks) {
    std::cout<<"\nTask List:\n";
    for (size_t i=0; i<tasks.size(); i++){
        std::cout<< i+1 <<". "<<tasks[i].description;
        if (tasks[i].completed) {
            std::cout<<" [ DONE ] ";

        }
        std::cout<<"\n";
    }
}
void
 markAsCompleted(std::vector<Task>& tasks) {
    int index;
    std::cout <<"Enter task number to mark ascompleted:";
    std::cin>>index;
    if(index >0 && index <= tasks.size()) {   
    tasks[index -1 ].completed = true;
    std::cout<<"Task marked as completed!\n";
    }
    else{
        std::cout<<"Invalid task number or task already completed.\n";
    }
}

void removeTask(std::vector<Task>& tasks){
    int index;
    std::cout<<"Enter Task number to remove:";
    std::cin>>index;
    if (index>0 && index<= tasks.size()){
        tasks.erase(tasks.begin()+ index - 1);
    }
    else{
        std::cout<<"Invalid Task number.\n";
    }
}
int main(){
    std::vector<Task> tasks;
    int choice;
    while(true){
        std::cout<<"\nTO DO LIST MENU\n";
        std::cout<<"1.Add your Task\n";
        std::cout<<"2.View yor Task\n";
        std::cout<<"3.Mark the task as completed\n";
        std::cout<<"4.Remove your Task\n";
        std::cout<<"5.Exit\n";
        std::cout<<"Enter your Choice!";
        std::cin>>choice;
        
        switch (choice){
            case 1:
            addTask(tasks);
            break;
            case 2:
            viewTask(tasks);
            break;
            case 3:
            markAsCompleted(tasks);
            break;
            case 4:
            removeTask(tasks);
            break;
            case 5:
            std::cout<<"Thank You!\n";
            return 0;
            default:
            std::cout<<"Invalid Choice,Please Try Again.\n";
            break;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
