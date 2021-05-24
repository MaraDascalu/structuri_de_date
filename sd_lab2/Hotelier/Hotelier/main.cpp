//
//  main.cpp
//  Hotelier
//
//  Created by Mara Dascalu on 25/03/2021.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string input_sting;
int rooms[10], n;


int main(int argc, const char * argv[]) {
    cin>>n>>input_sting;
    for (int i = 0 ; i < n; i++)
    {
        if (input_sting[i] == 'R')
        {
            for (int j = 9; j >= 0; j--)
                if (!rooms[j])
                {
                    rooms[j] = 1;
                    break;
                }
        }
        else
            if (input_sting[i] == 'L')
            {
                for (int j = 0; j <= 9; j++)
                    if (!rooms[j])
                    {
                        rooms[j] = 1;
                        break;
                    }
            }
            else
            {
                int room = input_sting[i] - '0';
                rooms[room] = 0;
            }
    }
    
    for (int i = 0; i <= 9; i++)
        cout<<rooms[i];
}
