#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure defination

struct SongInfo {
	// will contain the song name and the singer/band name and some other data possibly
	char name[30];
	char singer[30];
}; typedef struct SongInfo SongInfo;

struct Song {
	SongInfo info; // Every song can have an info (refer to previous structure)
	struct Song* next;
	struct Song* prev; // Song will make into a doubly Linked List to make scrolling through easier
}; typedef struct Song Song;

struct PlayList {
	char ListName[50]; // A playlist makes it easier to store song of similar type
	Song* songList;
	struct PlayList* next; // Multiple playlists can be there in a Music Player
	struct PlayList* prev; // To got to  the  last playlist
}; typedef struct PlayList PlayList;

// Structure defination ends here


// Function section

// Insert at Head for PlayList linked list
PlayList* PlayinsertHead(PlayList* PlayListHead){
	char name[50];
	printf("Enter name of the playlist -> ");
	while(getchar() != '\n'); // Flush the input buffer (more info in the main function implementation)
	scanf("%[^\n]s", name); // Name of the playlist with NLC as a delimiter to allow whitespaces 

	PlayList* New = (PlayList*)malloc(sizeof(PlayList)); // A new Playlist is allocated in the memory
	strncpy(New -> ListName, name, 50);	 // Name is stored
	New -> songList = NULL;

	if (PlayListHead == NULL){
		New -> next = NULL;
		PlayListHead = New;
		return PlayListHead;
	}
	New -> next = PlayListHead;
	PlayListHead = New;
	return PlayListHead;
}
//Insert at head for Song Linked List
Song* SonginsertHead(Song* SongHead){
	char song[30];
	char singer[30];
	printf("Enter song name -> ");
		while (getchar() != '\n');
	scanf("%[^\n]s", song);
	printf("Enter sing name -> ");
		while (getchar() != '\n');
	scanf("%[^\n]s", singer);

	Song* New = (Song*)malloc(sizeof(Song));
	strncat(New -> info.name, song, 30);
	strncat(New -> info.singer, singer, 30);

	if (SongHead == NULL){
		New -> next = NULL;
		SongHead = New;
		return SongHead;
	}
	New -> next = SongHead;
	SongHead = New;
	return SongHead;
}


// Menu
int showMenu(PlayList* PlayListHead){
	int choice;

	printf("===============================================================================\n\n");
	if (PlayListHead == NULL){
		printf("There are currently no playlists stored\n\n");
	}

	printf("Choose any of the options below: \n\n");
	printf("1 -> Make a playlist: \n");
	printf("2 -> Add song to playlist: \n");
	printf("3 -> Move to next playlist: \n");
	printf("4 -> Move to previous playlist: \n");
	printf("5 -> Play next song: \n");
	printf("6 -> Play previous song: \n");
	printf("7 -> Exit: \n");
	printf("\n");

	printf("Enter your choice -> ");
	scanf("%d", &choice);
	return choice;

}


// Main function
int main(int argc, char const *argv[])
{
	// The playlist will be declared as NULL, showing that no songs and no playlist exist
	PlayList* PlayListHead = NULL;

	int choice = showMenu(PlayListHead);
	while(choice != 7){
		switch (choice){ // Switch case to do stuff based on what selected by the user

			case 1:
				PlayListHead = PlayinsertHead(PlayListHead);
				break;

			case 2:
				PlayListHead -> songList = SonginsertHead(PlayListHead -> songList);
				break;

		}
		printf("\n\n");
		while(getchar() != '\n'); // This is done to flush the input buffer before taking the next input
		choice = showMenu(PlayListHead);
	}

	PlayList* ptr = PlayListHead;
	while(ptr != NULL){
		printf("%s -> ", ptr -> ListName);
		ptr = ptr -> next;
	}
	printf("\n");

	Song* ptr2 = PlayListHead -> songList;
	while(ptr2 != NULL){
		printf("%s -> ", ptr2 -> info);
		ptr = ptr -> next;
	}
	return 0;
}
