-   $HOME:  drwx------ 2 lschweis uzh8 4096 Oct 16 18:18 .

    - I have all permissions, others cannot see it

- $SCRATCH:     drwxr-x---+ 2 lschweis uzh8 4096 Sep 22 12:23 .
    
    - I have all permissions, group members can read and execute it (access and examine files)
    - I can access other's $SCRATCH but not $HOME as for them I fall into the group member 'group' --> have same permissions like that group
    
- Defalut permissions:
    - $HOME:    -rw-r--r-- 1 lschweis uzh8      0 Oct 16 18:30 test --> I can read and write, group members and all other users can read
    - $SCRATCH: -rw-r-----+ 1 lschweis uzh8 0 Oct 16 18:29 test --> I can read and write, group members can read, others have no permissions

    
- Permissions of /users/meberlei 
-   [eiger][lschweis@eiger-ln004 ~]$ cd /users/meberlei
    - bash: cd: /users/meberlei: Permission denied
    - drwx------ 2 meberlei uzh8 4096 Oct 16 17:35 /users/meberlei       
    - cannot access because I have no execution rights (I could find the folder with ls -l in /users)
    - should have set the same permissions like my $HOME folder
    - no i could not opent read or write content in it, I only have read permissions but to see whats in it, you need to have execution for a folder. I could list the files though as I should have read access as group member 

- What command can you use to set the access permissions for a directory so only the owner has (full) access?
    - chmod 700 directoryname

- Create a text file on $SCRATCH and set the permissions so that group members can write to it.
    - [eiger][lschweis@eiger-ln004 lschweis]$ chmod 760  grouptest.txt
    - [eiger][lschweis@eiger-ln004 lschweis]$ ls -l
    - -rwxrw----+ 1 lschweis uzh8 0 Oct 16 18:43 grouptest.txt
    
    - would be ok to write now, but $SCRATCH is preventing from doing so -->
    
    - [eiger][lschweis@eiger-ln004 lschweis]$ chmod 760  grouptest.txt
    - [eiger][lschweis@eiger-ln004 lschweis]$ ls -l
    - -rwxrw----+ 1 lschweis uzh8 0 Oct 16 18:43 grouptest.txt
    
    - now it should be possible of no folders above $SCRATCH are preventing others from doing so
    
    - --> changes for $scratch reverted 

-  Create a file and set its permissions to 000. Can you do anything with it now? Is the file completely lost?
    - for the moment no - i cannot do anything with it, access is completely denied.
    - no it is not lost, i can just change the permissions again, away from 000 if I'm the owner, using chmod


