#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    int id;
    char name[100];
    char artist[100];
    struct Song* next;
    struct Song* prev;
} Song;

Song* head = NULL;

void display() {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    
    Song* temp = head;
    do {
        printf("ID: %d, Name: %s, Artist: %s\n", temp->id, temp->name, temp->artist);
        temp = temp->next;
    } while (temp != head);
}

void addSongAtBeginning(int id, const char* name, const char* artist) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    newSong->id = id;
    strcpy(newSong->name, name);
    strcpy(newSong->artist, artist);

    if (head == NULL) {
        head = newSong;
        newSong->next = newSong->prev = newSong;
    } else {
        newSong->next = head;
        newSong->prev = head->prev;
        head->prev->next = newSong;
        head->prev = newSong;
        head = newSong;
    }
    display();
}

void addSongAtEnd(int id, const char* name, const char* artist) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    newSong->id = id;
    strcpy(newSong->name, name);
    strcpy(newSong->artist, artist);

    if (head == NULL) {
        head = newSong;
        newSong->next = newSong->prev = newSong;
    } else {
        newSong->next = head;
        newSong->prev = head->prev;
        head->prev->next = newSong;
        head->prev = newSong;
    }
    display();
}

void addSongAtPosition(int position, int id, const char* name, const char* artist) {
    if (position < 0) {
        printf("Invalid position!\n");
        return;
    }
    
    Song* newSong = (Song*)malloc(sizeof(Song));
    newSong->id = id;
    strcpy(newSong->name, name);
    strcpy(newSong->artist, artist);

    if (head == NULL) {
        head = newSong;
        newSong->next = newSong->prev = newSong;
    } else {
        Song* temp = head;
        for (int i = 0; i < position && temp->next != head; i++) {
            temp = temp->next;
        }
        newSong->next = temp->next;
        newSong->prev = temp;
        temp->next->prev = newSong;
        temp->next = newSong;
        if (temp == head->prev) {
            head->prev = newSong;  // Update last element's previous pointer if added at the end
        }
    }
    display();
}

void deleteSong(int id) {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    Song* temp = head;
    do {
        if (temp->id == id) {
            if (temp->next == head && temp->prev == head) { // Only one element
                free(temp);
                head = NULL;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                if (temp == head) head = temp->next;
                free(temp);
            }
            display();
            return;
        }
        temp = temp->next;
    } while (temp != head);
    
    printf("Song with ID %d not found.\n", id);
}

void updateSong(int id, const char* name, const char* artist) {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    Song* temp = head;
    do {
        if (temp->id == id) {
            if (name) strcpy(temp->name, name);
            if (artist) strcpy(temp->artist, artist);
            display();
            return;
        }
        temp = temp->next;
    } while (temp != head);
    
    printf("Song with ID %d not found.\n", id);
}

void retrieveArtistSongs(const char* songName) {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    Song* temp = head;
    char artist[100];
    int found = 0;

    do {
        if (strcmp(temp->name, songName) == 0) {
            strcpy(artist, temp->artist);
            found = 1;
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (!found) {
        printf("Song '%s' not found.\n", songName);
        return;
    }

    printf("Songs by artist '%s':\n", artist);
    temp = head;
    do {
        if (strcmp(temp->artist, artist) == 0 && strcmp(temp->name, songName) != 0) {
            printf("- %s\n", temp->name);
        }
        temp = temp->next;
    } while (temp != head);
}

void deallocatePlaylist() {
    if (head == NULL) return;

    Song* current = head;
    Song* nextSong;
    do {
        nextSong = current->next;
        free(current);
        current = nextSong;
    } while (current != head);
    
    head = NULL;
}

int main() {
    int choice, id, position;
    char name[100], artist[100];

    do {
        printf("\n--- Playlist Menu ---\n");
        printf("1. Add Song at Beginning\n");
        printf("2. Add Song at End\n");
        printf("3. Add Song at Specific Position\n");
        printf("4. Delete Song\n");
        printf("5. Update Song\n");
        printf("6. Retrieve Artist's Other Songs\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter song ID: ");
                scanf("%d", &id);
                printf("Enter song name: ");
                scanf(" %[^\n]", name);
                printf("Enter artist name: ");
                scanf(" %[^\n]", artist);
                addSongAtBeginning(id, name, artist);
                break;
            case 2:
                printf("Enter song ID: ");
                scanf("%d", &id);
                printf("Enter song name: ");
                scanf(" %[^\n]", name);
                printf("Enter artist name: ");
                scanf(" %[^\n]", artist);
                addSongAtEnd(id, name, artist);
                break;
            case 3:
                printf("Enter position (0 for beginning, or any positive integer): ");
                scanf("%d", &position);
                printf("Enter song ID: ");
                scanf("%d", &id);
                printf("Enter song name: ");
                scanf(" %[^\n]", name);
                printf("Enter artist name: ");
                scanf(" %[^\n]", artist);
                addSongAtPosition(position, id, name, artist);
                break;
            case 4:
                printf("Enter song ID to delete: ");
                scanf("%d", &id);
                deleteSong(id);
                break;
            case 5:
                printf("Enter song ID to update: ");
                scanf("%d", &id);
                printf("Enter new song name (or press enter to skip): ");
                scanf(" %[^\n]", name);
                printf("Enter new artist name (or press enter to skip): ");
                scanf(" %[^\n]", artist);
                updateSong(id, name, artist);
                break;
            case 6:
                printf("Enter song name to retrieve artist's songs: ");
                scanf(" %[^\n]", name);
                retrieveArtistSongs(name);
                break;
            case 7:
                deallocatePlaylist();
                printf("Exiting playlist system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
