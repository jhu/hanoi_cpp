#include <string>
#include <iostream>
#include "StackType.h"
#include "Disk.h"

void move(int n, StackType<Disk>& source, StackType<Disk>& temp, StackType<Disk>& dest)
{
	if(n>0) {
		// moves n-1 smaller disks from source rod to temp rod
		move(n-1, source, dest, temp);
		cout <<"disk " << source.top().getSize() << " is moved from " << source.getStackName() << " to " << dest.getStackName() << endl;
		// moves largest disk from source rod to dest rod
		dest.push(source.top());
		source.pop();
		// moves n-1 smaller disks from temp rod to dest rod
		move(n-1, temp, source, dest);
	}
}

void main()
{
	int disks;
    cout<<"Enter the number of disks!"<<endl;
    cin>>disks;

	// creates disks and stack them into source rod
    StackType<Disk> source;
	source.setStackName("Rod A");
    for(int i=disks; i>0; i--) {
		Disk d;
		d.setSize(i);
        source.push(d);
    }

	StackType<Disk> temp;
	temp.setStackName("Rod B");
    StackType<Disk> dest;
	dest.setStackName("Rod C");

	// run hanoi move
    move(disks,source,temp,dest);
	system("pause");
}