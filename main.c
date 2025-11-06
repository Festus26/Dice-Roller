#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Platform-specific includes and definitions
#ifdef _WIN32
    #include <windows.h>
    #define SLEEP_MS(ms) Sleep(ms)
    #define CLEAR_SCREEN "cls"
    #define strcasecmp _stricmp
#else
    #include <unistd.h>
    #define SLEEP_MS(ms) usleep((ms) * 1000)
    #define CLEAR_SCREEN "clear"
#endif 

const char* dice_faces_d4[4] = {
    // Face 1
    "   ┌─┐   \n"
    "  ╱ 1 ╲  \n"
    " ╱     ╲ \n"
    "└───────┘",
    
    // Face 2
    "   ┌─┐   \n"
    "  ╱ 2 ╲  \n"
    " ╱     ╲ \n"
    "└───────┘",
    
    // Face 3
    "   ┌─┐   \n"
    "  ╱ 3 ╲  \n"
    " ╱     ╲ \n"
    "└───────┘",
    
    // Face 4
    "   ┌─┐   \n"
    "  ╱ 4 ╲  \n"
    " ╱     ╲ \n"
    "└───────┘"
};

const char* dice_faces_d6[6] = {
    // Face 1
    "┌─────────┐\n"
    "│         │\n"
    "│    ●    │\n"
    "│         │\n"
    "└─────────┘",
    
    // Face 2
    "┌─────────┐\n"
    "│  ●      │\n"
    "│         │\n"
    "│      ●  │\n"
    "└─────────┘",
    
    // Face 3
    "┌─────────┐\n"
    "│  ●      │\n"
    "│    ●    │\n"
    "│      ●  │\n"
    "└─────────┘",
    
    // Face 4
    "┌─────────┐\n"
    "│  ●   ●  │\n"
    "│         │\n"
    "│  ●   ●  │\n"
    "└─────────┘",
    
    // Face 5
    "┌─────────┐\n"
    "│  ●   ●  │\n"
    "│    ●    │\n"
    "│  ●   ●  │\n"
    "└─────────┘",
    
    // Face 6
    "┌─────────┐\n"
    "│  ●   ●  │\n"
    "│  ●   ●  │\n"
    "│  ●   ●  │\n"
    "└─────────┘"
};

const char* dice_faces_d8[8] = {
    "  ╱╲  \n ╱ 1╲ \n╱   ╲\n╲   ╱\n ╲ _ ╱",
    "  ╱╲  \n ╱ 2╲ \n╱   ╲\n╲   ╱\n ╲ _ ╱",
    "  ╱╲  \n ╱ 3╲ \n╱   ╲\n╲   ╱\n ╲ _ ╱",
    "  ╱╲  \n ╱ 4╲ \n╱   ╲\n╲   ╱\n ╲ _ ╱",
    "  ╱╲  \n ╱ 5╲ \n╱   ╲\n╲   ╱\n ╲ _ ╱",
    "  ╱╲  \n ╱ 6╲ \n╱   ╲\n╲   ╱\n ╲ _ ╱",
    "  ╱╲  \n ╱ 7╲ \n╱   ╲\n╲   ╱\n ╲ _ ╱",
    "  ╱╲  \n ╱ 8╲ \n╱   ╲\n╲   ╱\n ╲ _ ╱"
};

const char* dice_faces_d10[10] = {
    "   ╱╲   \n  ╱ 1╲  \n ╱   ╲ \n╱_____╲",
    "   ╱╲   \n  ╱ 2╲  \n ╱   ╲ \n╱_____╲",
    "   ╱╲   \n  ╱ 3╲  \n ╱   ╲ \n╱_____╲",
    "   ╱╲   \n  ╱ 4╲  \n ╱   ╲ \n╱_____╲",
    "   ╱╲   \n  ╱ 5╲  \n ╱   ╲ \n╱_____╲",
    "   ╱╲   \n  ╱ 6╲  \n ╱   ╲ \n╱_____╲",
    "   ╱╲   \n  ╱ 7╲  \n ╱   ╲ \n╱_____╲",
    "   ╱╲   \n  ╱ 8╲  \n ╱   ╲ \n╱_____╲",
    "   ╱╲   \n  ╱ 9╲  \n ╱   ╲ \n╱_____╲",
    "   ╱╲   \n  ╱10╲  \n ╱   ╲ \n╱_____╲"
};

const char* dice_faces_d12[12] = {
    "  ╱───╲  \n ╱  1  ╲ \n╱_______╲",
    "  ╱───╲  \n ╱  2  ╲ \n╱_______╲",
    "  ╱───╲  \n ╱  3  ╲ \n╱_______╲",
    "  ╱───╲  \n ╱  4  ╲ \n╱_______╲",
    "  ╱───╲  \n ╱  5  ╲ \n╱_______╲",
    "  ╱───╲  \n ╱  6  ╲ \n╱_______╲",
    "  ╱───╲  \n ╱  7  ╲ \n╱_______╲",
    "  ╱───╲  \n ╱  8  ╲ \n╱_______╲",
    "  ╱───╲  \n ╱  9  ╲ \n╱_______╲",
    "  ╱───╲  \n ╱ 10  ╲ \n╱_______╲",
    "  ╱───╲  \n ╱ 11  ╲ \n╱_______╲",
    "  ╱───╲  \n ╱ 12  ╲ \n╱_______╲"
};

const char* dice_faces_d20[20] = {
    " ╱╲ \n╱ 1╲\n╲__╱",
    " ╱╲ \n╱ 2╲\n╲__╱",
    " ╱╲ \n╱ 3╲\n╲__╱",
    " ╱╲ \n╱ 4╲\n╲__╱",
    " ╱╲ \n╱ 5╲\n╲__╱",
    " ╱╲ \n╱ 6╲\n╲__╱",
    " ╱╲ \n╱ 7╲\n╲__╱",
    " ╱╲ \n╱ 8╲\n╲__╱",
    " ╱╲ \n╱ 9╲\n╲__╱",
    " ╱╲ \n╱10╲\n╲__╱",
    " ╱╲ \n╱11╲\n╲__╱",
    " ╱╲ \n╱12╲\n╲__╱",
    " ╱╲ \n╱13╲\n╲__╱",
    " ╱╲ \n╱14╲\n╲__╱",
    " ╱╲ \n╱15╲\n╲__╱",
    " ╱╲ \n╱16╲\n╲__╱",
    " ╱╲ \n╱17╲\n╲__╱",
    " ╱╲ \n╱18╲\n╲__╱",
    " ╱╲ \n╱19╲\n╲__╱",
    " ╱╲ \n╱20╲\n╲__╱"
};

// For d100 we generate a simple ASCII face at runtime (no static 100-entry array)

// Clear screen function
void clear_screen() {
    system(CLEAR_SCREEN);
}

// Function to display a dice face
void display_dice(int dice_type, int face_index) {
    printf("\n");
    switch(dice_type) {
        case 4:
            printf("%s\n", dice_faces_d4[face_index]);
            break;
        case 6:
            printf("%s\n", dice_faces_d6[face_index]);
            break;
        case 8:
            printf("%s\n", dice_faces_d8[face_index]);
            break;
        case 10:
            printf("%s\n", dice_faces_d10[face_index]);
            break;
        case 12:
            printf("%s\n", dice_faces_d12[face_index]);
            break;
        case 20:
            printf("%s\n", dice_faces_d20[face_index]);
            break;
        case 100: {
            int val = face_index + 1;
            printf("┌─────────┐\n");
            printf("│   %3d   │\n", val);
            printf("└─────────┘\n");
            break;
        }
    }
    printf("\n");
}

// Function to get dice name
const char* get_dice_name(int dice_type) {
    switch(dice_type) {
        case 4: return "D4 (Tetrahedron)";
        case 6: return "D6 (Cube)";
        case 8: return "D8 (Octahedron)";
        case 10: return "D10 (Pentagonal trapezohedron)";
        case 12: return "D12 (Dodecahedron)";
        case 20: return "D20 (Icosahedron)";
        case 100: return "D100 (Zocchihedron)";
        default: return "Unknown";
    }
}

// Animation function for rolling dice
void animate_dice_roll(int dice_type, int final_roll) {
    printf("🎲 Rolling the %s", get_dice_name(dice_type));
    fflush(stdout);
    
    // Show dots animation
    for (int i = 0; i < 3; i++) {
        SLEEP_MS(500);  // 0.5 second delay
        printf(".");
        fflush(stdout);
    }
    printf("\n\n");
    
    // Show random dice faces during rolling animation
    for (int i = 0; i < 8; i++) {
        clear_screen();  // Clear screen before each animation frame
        printf("🎲 Rolling the %s...\n", get_dice_name(dice_type));
        
        int random_face = rand() % dice_type;
        display_dice(dice_type, random_face);
        
        SLEEP_MS(200);  // 0.2 second delay
    }
    
    // Final result - clear screen one more time for clean final display
    clear_screen();
    printf("🎉 You rolled a %d! 🎉\n", final_roll + 1);
    display_dice(dice_type, final_roll);
}

// Function to display dice menu
int display_dice_menu() {
    printf("╔═══════════════════════════════════════╗\n");
    printf("║           SELECT DICE TYPE            ║\n");
    printf("╠═══════════════════════════════════════╣\n");
    printf("║ 1. D4  - 4-sided die (Tetrahedron)    ║\n");
    printf("║ 2. D6  - 6-sided die (Cube)           ║\n");
    printf("║ 3. D8  - 8-sided die (Octahedron)     ║\n");
    printf("║ 4. D10 - 10-sided die                 ║\n");
    printf("║ 5. D12 - 12-sided die (Dodecahedron)  ║\n");
    printf("║ 6. D20 - 20-sided die (Icosahedron)   ║\n");
    printf("║ 7. D100 - 100-sided die               ║\n");
    printf("║ 0. Exit                               ║\n");
    printf("╚═══════════════════════════════════════╝\n");
    printf("\nEnter your choice (0-7): ");
    
    int choice;
    scanf("%d", &choice);
    getchar(); // Consume newline
    
    switch(choice) {
        case 1: return 4;
        case 2: return 6;
        case 3: return 8;
        case 4: return 10;
        case 5: return 12;
        case 6: return 20;
        case 7: return 100;
        case 0: return 0;
        default: 
            printf("Invalid choice! Please try again.\n");
            SLEEP_MS(1000); // Wait 1 second
            return -1;
    }
}

// Function to parse dice type from command line argument
int parse_dice_argument(const char* arg) {
    if (strcasecmp(arg, "d4") == 0) return 4;
    if (strcasecmp(arg, "d6") == 0) return 6;
    if (strcasecmp(arg, "d8") == 0) return 8;
    if (strcasecmp(arg, "d10") == 0) return 10;
    if (strcasecmp(arg, "d12") == 0) return 12;
    if (strcasecmp(arg, "d20") == 0) return 20;
    if (strcasecmp(arg, "d100") == 0) return 100;
    return -1; // Invalid dice type
}

// Function to show usage information
void show_usage(const char* program_name) {
    printf("Usage: %s [dice_type]\n", program_name);
    printf("\nSupported dice types:\n");
    printf("  d4  - 4-sided die (Tetrahedron)\n");
    printf("  d6  - 6-sided die (Cube)\n");
    printf("  d8  - 8-sided die (Octahedron)\n");
    printf("  d10 - 10-sided die\n");
    printf("  d12 - 12-sided die (Dodecahedron)\n");
    printf("  d20 - 20-sided die (Icosahedron)\n");
    printf("\nExamples:\n");
    printf("  %s d20    # Roll a 20-sided die\n", program_name);
    printf("  %s d6     # Roll a 6-sided die\n", program_name);
    printf("  %s        # Interactive menu mode\n", program_name);
}

// Function to wait for user input
void wait_for_enter() {
    printf("Press Enter to roll the dice...");
    getchar();
}

int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed the random number generator
    
    // Check if command line argument was provided
    if (argc == 2) {
        // Direct dice roll mode
        int dice_type = parse_dice_argument(argv[1]);
        
        if (dice_type == -1) {
            printf("❌ Invalid dice type: %s\n\n", argv[1]);
            show_usage(argv[0]);
            return 1;
        }
        
        // Perform a single roll
        clear_screen();
        printf("🎲 Rolling %s...\n\n", argv[1]);
        
        int roll = rand() % dice_type;
        animate_dice_roll(dice_type, roll);
        
        printf("\n");
        return 0;
    } else if (argc > 2) {
        // Too many arguments
        printf("❌ Too many arguments!\n\n");
        show_usage(argv[0]);
        return 1;
    }
    
    int dice_type;
    char roll_again;
    
    clear_screen();
    printf("=======================================\n");
    printf("🎲    WELCOME TO DICE ROLLER!    🎲\n");
    printf("=======================================\n\n");
    
    while(1) {
        dice_type = display_dice_menu();
        
        if (dice_type == 0) {
            break;
        } else if (dice_type == -1) {
            clear_screen();
            printf("🎲    WELCOME TO DICE ROLLER!    🎲\n\n");
            continue;
        }
        
        // Rolling loop for selected dice
        do {
            clear_screen();
            printf("🎲 Selected: %s 🎲\n\n", get_dice_name(dice_type));
            wait_for_enter();
            
            int roll = rand() % dice_type; 
            animate_dice_roll(dice_type, roll);
            
            printf("\nRoll again with same dice? (y/n): ");
            scanf(" %c", &roll_again);
            getchar(); 
            
        } while (roll_again == 'y' || roll_again == 'Y');
        
        clear_screen();
        printf("🎲 Returning to dice selection... 🎲\n\n");
        SLEEP_MS(1000); // Wait 1 second
    }
    
    clear_screen();
    printf("=======================================\n");
    printf("🎲   Thanks for playing! Goodbye! 🎲\n");
    printf("=======================================\n");
    
    return 0;
}

