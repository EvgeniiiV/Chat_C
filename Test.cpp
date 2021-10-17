#include<iostream>
using namespace std;
#include<string>
#include "Chat_C.cpp"
#include <vector>
#include "User.cpp"
#include <algorithm> 


#define MaxUserCount 10//limit of Users
#define MaxGroupCount 100//limit of contacts (groups of users) 
#define MaxMessageCount 200//limit of messages in one group 

#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW


int main()
{  
       
        vector<User<string>>user;
        user.reserve(MaxUserCount);        
        vector<vector<string>>group;//to storage user's names in the group (contact)
        group.reserve(MaxGroupCount);      
        vector<vector<string>>mess;//messages
        mess.reserve(MaxMessageCount);      
        vector<string>temp;//keeps cuttent group's composition 
        temp.reserve(MaxGroupCount);
        vector <string>temp_mes;//for temporary storage of messages (case 5, 6)
        temp_mes.reserve(20);        
        size_t user_ind = 0;//to keep current index of AUTHORIZED USER       
        string name, login, password;//current user
        string contact_name;//current contact
        string message;
        size_t choice = 1;//switch
        bool ch(true);//while    
        bool n;//cycles   
        size_t num_of_contact;//to chose the contact in case 4
        size_t presence = 0;//number of groups where this user lists

        cout << "REGISTRATION" << endl;
        while (ch)
        {
            switch (choice)
            {


            case 1:
                name.clear();
                n = true;
                while (n)
                {
                    cout << "Enter your NAME" << endl;
                    while (name.empty())
                    {
                        getline(cin, name);
                    }
                    for (size_t k = 0; k < user.size(); k++)
                    {
                        if (user[k].get_name() == name)
                        {
                            n = false;
                            break;
                        }
                    }
                    if (!n)
                    {
                        cout << "This name is already used. Choose another name" << endl;
                        name.clear();
                        n = true;
                    }
                    else n = false;
                }
                n = true;
                while (n)
                {
                    login.clear(); password.clear();
                    cout << "Enter LOGIN" << endl;
                    while (login.empty())
                    {
                        getline(cin, login);
                    }
                    cout << "Enter PASSWORD" << endl;
                    while (password.empty())
                    {
                        getline(cin, password);
                    }
                    for (size_t k = 0; k < user.size(); k++)
                    {
                        if (compare_LP <string>(user[k].get_log_pas(), login, password))
                        {
                            n = false;
                            break;
                        }
                    }
                    if (!n)
                    {
                        cout << "Change the login and try again" << endl;
                        login.clear(); password.clear();
                        n = true;
                    }
                    else  n = false;
                }
                choice = request <string, size_t>("to continue REGISTRATION press key 1, for AUTHORIZATION press key 2", 1, 2, user.size());
                user.push_back(User<string>(name, login, password));                

                cout << "REGISTERED USERS:" << endl;
                for (size_t i = 0; i < user.size(); i++)
                    cout << i + 1 << ". " << user[i].get_name() << endl;
                break;

            case 2:
                cout << "AUTHORIZATION" << endl;
                n = true;
                while (n)
                {
                    name.clear(); login.clear(); password.clear();
                    cout << "Enter LOGIN" << endl;
                    cin.clear();
                    while (login.empty())
                    {
                        getline(cin, login);

                    }
                    cout << "Enter PASSWORD" << endl;
                    while (password.empty())
                    {
                        getline(cin, password);

                    }
                    for (size_t k = 0; k < user.size(); k++)
                    {
                        if (compare_LP <string>(user[k].get_log_pas(), login, password))
                        {
                            user_ind = k;
                            n = false;
                            break;
                        }
                    }
                    if (n)
                    {
                        cout << "Invalid password or login. Try again" << endl;
                        login.clear(); password.clear();
                        n = true;
                    }
                    else n = false;
                }
                name = user[user_ind].get_name();
                cout << "HELLO " << name << "!" << endl << endl;
                choice = request <string, size_t>("ADD a CONTACT: press key 3, CHOOSE a CONTACT: press key 4", 3, 4,user.size());

                //check if this USER has contacts (if choice == 4 && number of groups = 0)
                if (choice == 4 && group.size() == 0)
                {
                    cout << "You don't have contacts yet" << endl; choice = 3;
                }
                n = true;
                //check if this USER has contacts (if choice == 4 && numOf_groups = 0)
                if (choice == 4 && group.size() > 0)
                {
                    for (size_t i = 0; i < group.size(); i++)
                    {
                        for (size_t j = 0; j < group[i].size(); j++)
                        {
                            if (group[i][j] == user[user_ind].get_name())
                            {
                                n = false;
                                break;
                            }
                        }if (n == false) break;
                    }

                    if (n)
                    {
                        cout << "You don't have contacts yet" << endl;
                        choice = 3;
                        break;
                    }
                }

                break;

            case 3:

                //to prevent entry to case 3 if the user already lists in all groups                  
                presence = 0;//number of groups where this user lists
                for (size_t i = 0; i < group.size(); i++)
                    for (size_t j = 0; j < group[i].size(); j++)
                        if (group[i][j] == name)
                        {
                            presence++;
                        }
                //cheks is there opporutity to create more contacts
                if (presence >= Presence(user.size()))
                {
                    cout << user[user_ind].get_name() << ", you are already in touch with all possible contacts" << endl;
                    choice = 4;
                }
                n = true;
                if (choice != 4)
                {
                    while (n)//crearing of contacts
                    {
                        cout << "CREATE a CONTACT" << endl;
                        contact_name.clear();
                        cout << "Enter the NAME of CONTACT" << endl;
                        while (contact_name.empty())
                        {
                            getline(cin, contact_name);
                        }
                        //Chat with yourself is impossible
                        if (user[user_ind].get_name() == contact_name)
                        {
                            cout << "Chat with yourself is impossible" << endl;
                            continue;
                        }
                        //  the name is among of the registered
                        for (size_t i = 0; i < user.size(); i++)
                        {
                            if (user[i].get_name() == contact_name)
                            {
                                n = false;
                                break;
                            }
                        }
                        //UNREGISTERED user
                        if (n)
                        {
                            cout << "UNREGISTERED user. Try again" << endl;
                            contact_name.clear();
                        }
                        else n = false;

                        //if This USER has already been ADDED to this group
                        if (temp.size() != 0)
                            for (size_t i = 0; i < temp.size(); i++)
                                //if This USER has already been ADDED to this group
                                if (find(temp.begin(), temp.end(), contact_name) != temp.end())
                                {
                                    cout << "This USER has already been ADDED to this group." << endl;
                                    n = true;
                                    break;
                                }
                    }
                    name = user[user_ind].get_name();
                    if (temp.size() == 0)
                        temp.push_back(name);//authorized user's name -> temp
                    temp.push_back(contact_name);//contact name -> temp
                    sort(temp.begin(), temp.end());
                    cout << contact_name << " was ADDED" << endl;
                    choice = request <string, size_t>
                     ("ADD a CONTACT to THIS group: press key 3, CHOOSE a CONTACT: press key 4", 3, 4, user.size());

                    //if ALL the USERS have already been ADDED to this group and number of groups == 0

                    if ((choice == 3 || choice == 4) && temp.size() >= user.size() && group.size() == 0)
                    {
                        //Temp -> Group               
                        group.push_back(temp);
                        cout << "Your new group:" << endl;
                        for (size_t s = 0; s < temp.size(); s++)
                            cout << s + 1 << ". " << temp[s] << endl;                        
                        cout << "All registred USERS are in this group" << endl;                        
                        choice = 4;
                        temp.clear();
                        break;
                    }
                    //if ALL the USERS have already been ADDED to this group 
                    //and there are number of groups more than 0
                    if ((choice == 3 || choice == 4) && temp.size() >= user.size() && group.size() > 0)
                    {
                        n = true;
                        for (size_t i = 0; i < group.size(); i++)//check if This Group is already exists                           
                            if (temp == group[i])
                            {
                                cout << "This Group is already exists, it's NUMBER is " << i << endl;
                                cout << "All registred USERS are in this group" << endl;
                                choice = 4;
                                temp./*temp_*/clear();
                                n = false;
                                break;
                            }
                        if (n)
                        {   //Temp -> Group                
                            group.push_back(temp);
                            cout << "Your new group:" << endl;
                            for (size_t s = 0; s < temp.size(); s++)
                            cout << s + 1 << ". " << temp[s] << endl;                            
                            cout << "All registred USERS are in this group" << endl;                            
                            choice = 4;
                            temp.clear();
                            break;
                        }
                    }
                    //If NOT all users were involved in the group and user goes to choose next contact                          
                    else if ((choice == 4) && (temp.size() <user.size()) && (group.size() > 0))
                    {
                        //check if This Group is already exists
                        n = true;
                        for (size_t i = 0; i < group.size(); i++)
                            //if there is the same group                            
                            if (temp == group[i])
                            {
                                cout << "This Group is already exists, it's NUMBER is " << i << endl;
                                n = false;
                                temp.clear();
                                break;
                            }

                        if (n)
                        {     //Temp -> Group
                            group.push_back(temp);
                            cout << "Your new group:" << endl;
                            for (size_t s = 0; s < temp.size(); s++)
                                cout << s + 1 << ". " << temp[s] << endl;                           
                            temp.clear();
                            break;
                        }
                    }
                    //if the group in temp was created but number Of_groups == 0 
                    else if ((choice == 4) && (temp.size() < user.size()) && (group.size() == 0))
                    {     //Temp -> Group                    
                        group.push_back(temp);
                        cout << "Your new group:" << endl;
                        for (size_t s = 0; s < temp.size(); s++)
                            cout << s + 1 << ". " << temp[s]<< endl;                        
                        temp.clear();
                        break;
                    }
                    //If we return in 3 to add a contact in this group
                    //and NOT all users were involved in this group 
                    else if (choice == 3 && temp.size() < user.size())
                    {
                        cout << "Your group:" << endl;
                        for (size_t s = 0; s < temp.size(); s++)
                            cout << s + 1 << ". " << temp[s] << endl;
                        n = true;
                    }
                }
                break;

            case 4://choose a contact      

                choice = request <string, size_t>
                 ("CHAT with your contacts: press key 4, MESSAGE for everyone: press key 6", 4, 6, user.size());
                if (choice == 6) break;
                cout << "Your contacts (groups):" << endl;
                for (size_t i = 0; i < group.size(); i++)
                    for (size_t j = 0; j < group[i].size(); j++)
                        if (group[i][j] == user[user_ind].get_name())
                        {
                            cout << '\n' << i << ". ";
                            for (size_t k = 0; k < group[i].size(); k++)
                                cout << group[i][k] << " ";
                            cout << endl;
                        }cout << endl;
                do
                {
                    cout << "Choose NUMBER of CONTACT (GROUP)" << endl;
                    do
                    {
                        cin.clear();
                        streamsize L = cin.rdbuf()->in_avail();
                        cin.ignore(L);
                        cin >> num_of_contact;
                        if (!cin)
                            cout << "ENTER a DIGIT" << endl;
                    } while (!cin);
                    //prevents obviously wrong input
                    if (num_of_contact >= group.size() || num_of_contact < 0)
                    {
                        cin.clear(); cin.ignore();
                        cout << "Error: INVALID number of CONTACT" << endl;
                    }
                } while (num_of_contact >= group.size() || num_of_contact < 0);
                //check if this USER belongs to this contact
                if (num_of_contact < group.size())
                {
                    n = true;
                    for (size_t j = 0; j < group[num_of_contact].size(); j++)
                        if (group[num_of_contact][j] == user[user_ind].get_name())
                        {
                            choice = 5;
                            n = false;
                            break;
                        }

                    if (n)
                    {
                        cout << "It is NOT YOUR GROUP. Try again" << endl;
                        choice = 4;
                    }
                }

                break;                

            case 5://to send message

                if (num_of_contact < mess.size())
                    for (size_t i = 0; i < mess[num_of_contact].size(); i++)
                    {
                        cout << num_of_contact << ". ";
                        cout << mess[num_of_contact][i] << endl;
                    }                
                while(choice == 5)
                {
                 cout << "\nTEXT your message" << endl;
                 cin.clear(); cin.ignore();
                 getline(cin, message);
                 temp_mes.push_back(user[user_ind].get_name() + ": " + message);
                 choice = next_request<size_t>();//to choose further destination
                }
                //if there is new group without messages
                if (mess.size() <= num_of_contact )
                    mess.push_back(temp_mes);
                else
                {for (size_t i = 0; i < temp_mes.size();i++)
                    mess[num_of_contact].push_back(temp_mes[i]);
                }
                temp_mes.clear();                
                if (choice == 7) ch = false;                
                break;

            case 6://Message for everyone
                cout << "\nTEXT your message" << endl;
                cin.clear(); cin.ignore();
                getline(cin, message);
                //to push messages to all existing groups with messages
                for (size_t i = 0; i < mess.size(); i++)
                {                    
                    mess[i].push_back(user[user_ind].get_name() + ": " + message);
                }
                //to push message to new group without messages
                if (group.size() > mess.size())
                {                    
                    temp_mes.push_back(user[user_ind].get_name() + ": " + message);
                    mess.push_back(temp_mes);               
                }                
                temp_mes.clear();
                choice = next_request<size_t>();//to choose further destination
                if (choice == 7) ch = false;
                break;
            }
        }
      
    _CrtDumpMemoryLeaks();
    return 0;
}

