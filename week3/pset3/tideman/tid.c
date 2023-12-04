#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;
int voter_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }
        for (int k = 0; k < candidate_count; k++)
        {
            printf("%i", ranks[k]);
        }
        printf("\n");

        record_preferences(ranks);

        printf("\n");
    }
    for (int i =0; i < candidate_count; i++)
    {
        for (int j =0; j < candidate_count; j++)
        {
            printf("%i", preferences[i][j]);
        }
        printf("\n");
    }
    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            //printf("%i\n", ranks[rank]);
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i =0; i < candidate_count -1 ; i++)
    {
        for (int j =i+1; j < candidate_count; j++)
        {
            for (int k =0; k < candidate_count; k++)
            {
                if (ranks[k] == i)
                {
                    preferences[i][j] += 1;
                    preferences[j][i] = voter_count - preferences[i][j];
                    break;
                }
                else if (ranks[k] == j)
                {
                    break;
                }
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    int n = 0;
        for (int i =0; i < candidate_count -1 ; i++)
        {
            for (int j =i+1; j < candidate_count; j++)
            {
                if (preferences[i][j] > preferences[j][i])
                {
                    pairs[n].winner = i;
                    pairs[n].loser = j;
                    n += 1;
                }
                else if (preferences[i][j] < preferences[j][i])
                {
                    pairs[n].winner = j;
                    pairs[n].loser = i;
                    n += 1;
                }
            }
        }
        pair_count = n;
        printf("%i\n", pair_count);
        for (int i = 0; i < pair_count; i++)
        {
            printf("%i %i\n", pairs[i].winner, pairs[i].loser);
        }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    for (int i =0; i < pair_count-1; i++)
    {
        int x[2];
        x[0] = pairs[i].winner;
        x[1] = pairs[i].loser;
        int n = 0;
        for (int j = i+1; j < pair_count; j++)
        {
            if (preferences[pairs[j].winner][pairs[j].loser] > preferences[x[0]][x[1]])
            {
                x[0] = pairs[j].winner;
                x[1] = pairs[j].loser;
                n = j;
            }
        }
    pairs[n].winner = pairs[i].winner;
    pairs[n].loser = pairs[i].loser;
    pairs[i].winner = x[0];
    pairs[i].loser = x[1];
    }
    for (int i = 0; i < pair_count; i++)
    {
            printf("%i %i\n", pairs[i].winner, pairs[i].loser);
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        int x = pairs[i].winner;
        for (int j = i+1 ; j < pair_count; j++)
        {
            if (locked[pairs[j].winner][pairs[j].loser])
            {
                if (pairs[j].loser == x)
                {
                    break;
                }
            }
        }
        locked[pairs[i].winner][pairs[i].loser] = true;
        printf("%i %i is true\n", pairs[i].winner, pairs[i].loser);
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    int winner;
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        if (locked[pairs[i].winner][pairs[i].loser])
        {
            winner = pairs[i].winner;
            int n;
            for (int j = 0 ; j < pair_count; j++)
            {
                if (locked[pairs[j].winner][pairs[j].loser])
                {
                        if (pairs[j].loser == winner)
                        {
                            //printf("%s\n", candidates[pairs[i].winner]);
                            break;
                        }
                }
                n = j + 1;
            }
            if (n == pair_count)
            {
                break;
            }
            //printf("%s\n", candidates[pairs[i].winner]);
        }
    }
    printf("%s\n", candidates[pairs[winner].winner]);
    return;
}