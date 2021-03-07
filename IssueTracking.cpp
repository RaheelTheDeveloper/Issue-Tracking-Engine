#include <bits/stdc++.h>
#include <ctime>
using namespace std;

//To print End date and Start date
time_t t = time(0); 
struct tm * timeStruct = localtime(&t);

//To Iterate id 
int userIter=0;
int issueIter=0;

class user {
// Access specifier 
    public: 
    // Data Members 
    int  user_id;
    string user_name;
    // Member Functions()
    int adduser(string username);
    void removeuser(int id);
    string getUser(int id);
    string getUsers();
};

// Globally declared vector array for user
vector<user>obj; 
vector<user>::iterator it;

//Issue class
class Issue {
// Access specifier 
    public: 
    // Data Members 
    int  issueId;
    string issue;
    string issueState="";
    string issueComment="";
    int assigneduser=0;
    string startdate="";
    string enddate="";
    // Member Functions()
    int addIssue(string issuename);
    void removeIssue(int id);
    string getIssue(int id);
    string getIssues(string state, int userid, string startdate, string enddate);
    void getIssueComment(int id, string data1);
    void assignUser(int userId, int issueId);
    void setIssueState(int issueId, string state,string data1);
};

// Globally declared vector array for issue
vector<Issue>obj2; 
vector<Issue>::iterator it2;

// To add user and return the id
int user::adduser(string username){   
         user_name = username;
         userIter++;
         cout<<"The user id="<<userIter<<endl;
         return(userIter);  
}

// To add issue and return the id also update the entered time
int Issue::addIssue(string issuename){   
         issue = issuename;
         issueIter++;
         startdate = to_string(timeStruct->tm_mday) + '/' + to_string(timeStruct->tm_mon) + '/' +  to_string(timeStruct->tm_year+1900);
         cout<<"The issue id="<<issueIter<<endl;
         return(issueIter);  
}

// Remove user Todo: need to remove if assigned any issue
void user::removeuser(int id){
    int check=0;
        for(it=obj.begin(); it!= obj.end(); it++){
             if(it->user_id==id){  
                obj.erase(it); check=1;
                }         
       }
       if(check==0)
         cout<<"The user with this Id doesn't exist";
}

// Remove the issue
void Issue::removeIssue(int id){
    int check=0; 
        for(it2=obj2.begin(); it2!= obj2.end(); it2++){
             if(it2->issueId==id){  
                obj2.erase(it2); check=1;
            }         
       }
       if(check==0)
          cout<<"The issue with this Id doesn't exist";
}

// Get the specfic user by id
string user::getUser(int id){  
        for(it=obj.begin(); it!= obj.end(); it++){
             if(it->user_id==id){  
                     return (it->user_name);
                }         
       }
       return("No user with this id");
}

// Get specifc issue by the id
string Issue::getIssue(int id){  
        for(it2=obj2.begin(); it2!= obj2.end(); it2++){
             if(it2->issueId==id){  
                     return (it2->issue);
                }         
       }
       return("No Issue with this Id");
}

//Get list of users
string user::getUsers(){  
           string data;
        for(it=obj.begin(); it!= obj.end(); it++){
             {  
                    data += it->user_name + "\n";
             }         
       }
       return(data); 
}

//Get list Issues with different fileters 
string Issue::getIssues(string state, int userId, string startdate, string enddate){  
        string data;        
        //filter the issue according to state
        if(!state.empty()){
            for(it2=obj2.begin();it2!= obj2.end(); it2++){
                if(it2->issueState==state)
                    data += it2->issue + " " + it2->issueState +" "+it2->issueComment+" "+ to_string(it2->assigneduser)+" "
                     +it2->startdate+" "+it2->enddate+"\n";
                }         
        }
        //filter the issue according to assigned user id
        if(userId!=0){
            for(it2=obj2.begin();it2!= obj2.end(); it2++){
                if(it2->assigneduser==userId)
                    data += it2->issue + " " + it2->issueState +" "+it2->issueComment+" "+ to_string(it2->assigneduser)+" "
                     +it2->startdate+" "+it2->enddate+"\n";
                }         
        }
        // If all filters are oof
        if(userId==0 && state.empty() && startdate.empty() && enddate.empty()){
             for(it2=obj2.begin();it2!= obj2.end(); it2++){
                    data += it2->issue + " " + it2->issueState +" "+it2->issueComment+" "+ to_string(it2->assigneduser)+" "
                     +it2->startdate+" "+it2->enddate+"\n";
                }
        }
        //For Start date filter
        if(!startdate.empty()){
            for(it2=obj2.begin();it2!= obj2.end(); it2++){
                if(it2->startdate==startdate)
                    data += it2->issue + " " + it2->issueState +" "+it2->issueComment+" "+ to_string(it2->assigneduser)+" "
                     +it2->startdate+" "+it2->enddate+"\n";
                }
         }
         //For end date filter
        if(!enddate.empty()){
            for(it2=obj2.begin();it2!= obj2.end(); it2++){
                if(it2->enddate==startdate)
                    data += it2->issue + " " + it2->issueState +" "+it2->issueComment+" "+ to_string(it2->assigneduser)+" "
                     +it2->startdate+" "+it2->enddate+"\n";
                }
         }
       return(data); 
}

//To add the issue comment
void Issue::getIssueComment(int id, string data1){  
        int i=0;
        for(it2=obj2.begin(); it2!= obj2.end(); it2++){  
                 if(it2->issueId==id){
                    it2->issueComment=data1;
                    i=1;
                 }
             }
        if(i==0)
            cout<<"Issue with this Id soen't exist";         
}

// To assign user to issue with two different checks of user id and issue id  
void Issue::assignUser(int userId, int issueId){   
        int i=0;
        for(it=obj.begin(); it!= obj.end(); it++){  
                 if(it->user_id==userId){
                    i=1;
                 }
        }
        if(i==1){
            for(it2=obj2.begin(); it2!= obj2.end(); it2++){
                if(it2->issueId==issueId)
                 { 
                     it2->assigneduser=userId;
                     cout<<it2->issueId<<" "<< it2->issue <<"  "<<it2->issueComment<<" "<<it2->assigneduser<<endl;
                 }       
            }
            if(i=0)
               cout<<"The issue with this id doesn't exist";           
        }
        else
        {
          cout<<"The user with this id doesn't exist";
        }
}

//Set issue state if states is done will save the end time
void Issue::setIssueState(int issueid, string state, string data1){
    for(it2=obj2.begin(); it2!= obj2.end(); it2++){
        if(it2->issueId==issueid){
            it2->issueState=state; it2->issueComment=data1;
            if(state=="Done")
                  it2->enddate = to_string(timeStruct->tm_mday) + '/' + to_string(timeStruct->tm_mon) + '/' +  to_string(timeStruct->tm_year+1900);
        }
    }
}
void testScanarios(){
    user  *s1 = new user;
    Issue *s2 = new Issue;
    int userid, issueid;
     s1->user_id=s1->adduser("steve");
     s2->issueId=s2->addIssue("The app crashes on login");
     obj.push_back(*s1);obj2.push_back(*s2);
     s2->assignUser(s1->user_id,s2->issueId);
     string state="TODO";
     s2->setIssueState(s2->issueId,state,"I am on it");
}

int main() {

//     testScanarios();
     int i=0;
    int userid,issueid;
    string data,list,data1,data2;
    user  *s1 = new user;
    Issue *s2 = new Issue;
    int opt;
    cout<<"Enter 1  to add user\n\
Enter 2  to add Issue \n\
Enter 3  to remove user \n\
Enter 4  to remove issue \n\
Enter 5  to get specific user \n\
Enter 6  to get specific issues \n\
Enter 7  to get list of user \n\
Enter 8  to add comment to issue \n\
Enter 9  assign user userid to issue \n\
Enter 10 update state \n\
Enter 11 list the issues"<<endl;
   while(i==0){
       cout<<"Enter option Number=";
       cin>>opt;
       switch(opt){
       // Enter User
       case 1:
            cin.ignore();
            cout<<"Enter username=";
            getline(cin,data);
            s1->user_id=s1->adduser(data);
            obj.push_back(*s1);
        break;
        // Enter Issue
       case 2:
            cin.ignore();
            cout<<"Enter Issue=";
            getline(cin,data);
            s2->issueId=s2->addIssue(data);
            obj2.push_back(*s2);
        break;
    //  Remove User
       case 3:
            cout<<"Enter User Id=";
            cin>>userid;
            s1->removeuser(userid);
        break;
        // Remove Issue
        case 4:
            cout<<"Enter Issue Id=";
            cin>>userid;
            s2->removeIssue(userid);
        break;
        // Get Specific User
       case 5:
            cout<<"Enter the id of users=";
            cin>>userid;
            data=s1->getUser(userid);
            cout<<"The user is="<<data;
            break;
        // Get Specific Issue
       case 6:
            cout<<"Enter the id of users=";
            cin>>userid;
            data=s2->getIssue(userid);
            cout<<"The issue is="<<data;
            break;
        // Get list of users
       case 7:
            list=s1->getUsers();
            cout<<list;
            break;
        // Add comment to issues
       case 8:
            cout<<"Enter issue id=";cin>>issueid; 
            cin.ignore();
            cout<<"Enter comment="; getline(cin,data); 
            s2->getIssueComment(issueid,data);
            break;
      // Assign user id to issue
      case 9:
            cout<<"Enter issue id=";cin>>issueid; 
            cout<<"Enter user id=";cin>>userid;
            s2->assignUser(userid,issueid);
            break;
      // Update the state
      case 10: 
            cout<<"Enter the issue id=";cin>>issueid;
            cin.ignore();
            cout<<"Enter state="; getline(cin,data);
            cout<<"Enter comment="; getline(cin,data1);
            s2->setIssueState(issueid,data,data1);
            break;
        // Print all the Issues
      case 11:
            cout<<"Enter the User id=";cin>>userid;
            cin.ignore();
            cout<<"Enter state="; getline(cin,data);
            cout<<"Enter startdate="; getline(cin,data1);
            cout<<"Enter enddate="; getline(cin,data2);
            list=s2->getIssues(data,userid,data1,data2);
            cout<<list;
            break;
       default:
         cout<<"Wrong input";
         break;  
       } 
       cout<<endl;       
   } 
}
