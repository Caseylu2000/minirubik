#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const uint8_t heuristic_table[729] = {                      // hardcoded array, this is the heuristic table we built using build_table() which we are no longer need if we compute all the tables we need.
    0, 5, 5, 4, 4, 5, 4, 6, 3, 6, 3, 4, 4, 3, 5, 5, 
    1, 5, 5, 4, 4, 5, 5, 3, 3, 5, 4, 4, 3, 6, 4, 5, 
    4, 5, 4, 4, 4, 4, 2, 3, 5, 4, 5, 5, 4, 5, 5, 4, 
    5, 4, 3, 5, 3, 5, 4, 5, 4, 5, 5, 5, 4, 4, 5, 5, 
    4, 5, 4, 5, 4, 5, 4, 5, 4, 4, 4, 5, 5, 5, 3, 4, 
    4, 5, 3, 5, 4, 5, 4, 5, 4, 5, 4, 4, 4, 4, 5, 5, 
    4, 4, 5, 4, 5, 5, 5, 4, 5, 4, 4, 5, 4, 5, 3, 5, 
    6, 5, 5, 4, 6, 4, 5, 5, 4, 5, 5, 6, 5, 4, 6, 5, 
    4, 5, 6, 4, 4, 5, 5, 6, 3, 4, 4, 5, 6, 4, 3, 5, 
    2, 5, 4, 5, 5, 5, 3, 5, 5, 5, 4, 5, 4, 5, 6, 5, 
    5, 5, 5, 5, 3, 6, 4, 3, 4, 3, 5, 4, 5, 5, 2, 5, 
    4, 5, 4, 5, 4, 5, 4, 4, 4, 4, 3, 5, 4, 5, 5, 4, 
    4, 5, 3, 5, 6, 4, 5, 5, 4, 5, 4, 5, 5, 5, 4, 4, 
    5, 5, 4, 4, 5, 5, 5, 5, 4, 4, 5, 4, 6, 5, 5, 5, 
    6, 6, 5, 4, 3, 4, 4, 5, 5, 6, 4, 6, 5, 5, 5, 5, 
    5, 4, 5, 5, 3, 5, 4, 4, 5, 4, 5, 5, 5, 4, 3, 3, 
    5, 4, 4, 5, 5, 6, 4, 3, 4, 4, 4, 4, 2, 5, 4, 4, 
    4, 4, 5, 4, 4, 4, 4, 4, 5, 5, 4, 3, 5, 5, 5, 5, 
    4, 5, 2, 4, 5, 3, 4, 5, 3, 4, 5, 5, 4, 5, 5, 3, 
    4, 4, 4, 5, 6, 4, 5, 4, 5, 3, 5, 4, 5, 5, 5, 4, 
    5, 4, 5, 4, 3, 3, 5, 3, 4, 4, 5, 5, 4, 4, 4, 5, 
    5, 4, 5, 4, 4, 3, 3, 5, 4, 4, 5, 3, 5, 2, 4, 4, 
    5, 4, 4, 4, 5, 5, 5, 5, 5, 4, 5, 4, 5, 4, 5, 4, 
    5, 5, 4, 5, 5, 5, 5, 4, 5, 5, 4, 5, 3, 4, 4, 5, 
    4, 4, 5, 4, 5, 5, 5, 3, 4, 3, 3, 4, 2, 3, 3, 5, 
    4, 4, 5, 5, 4, 5, 5, 2, 5, 4, 4, 5, 4, 4, 4, 4, 
    5, 5, 5, 2, 5, 5, 5, 4, 5, 4, 1, 5, 6, 5, 2, 5, 
    5, 4, 3, 4, 5, 4, 5, 5, 4, 5, 6, 3, 4, 4, 4, 4, 
    4, 5, 4, 4, 5, 3, 4, 5, 4, 4, 3, 5, 5, 5, 4, 5, 
    4, 5, 5, 6, 5, 4, 6, 5, 5, 5, 5, 4, 5, 5, 5, 5, 
    3, 5, 4, 5, 4, 4, 5, 5, 3, 4, 5, 5, 4, 4, 4, 5, 
    4, 5, 4, 5, 4, 5, 4, 4, 5, 4, 4, 5, 5, 4, 4, 5, 
    5, 4, 5, 5, 3, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 
    5, 3, 4, 5, 6, 4, 5, 5, 5, 4, 4, 5, 4, 5, 4, 4, 
    5, 5, 4, 4, 5, 5, 4, 5, 5, 4, 6, 4, 4, 5, 4, 5, 
    6, 5, 6, 6, 5, 5, 4, 5, 2, 5, 5, 5, 5, 5, 3, 4, 
    3, 4, 5, 5, 4, 4, 3, 6, 6, 5, 5, 5, 5, 5, 6, 4, 
    4, 5, 5, 4, 4, 5, 6, 5, 5, 4, 5, 6, 5, 3, 4, 4, 
    5, 5, 5, 6, 5, 6, 4, 5, 5, 5, 6, 4, 4, 5, 4, 4, 
    4, 4, 5, 4, 4, 5, 4, 5, 4, 3, 4, 5, 5, 5, 5, 5, 
    5, 5, 4, 4, 5, 4, 4, 5, 3, 5, 3, 4, 3, 5, 4, 4, 
    5, 4, 5, 5, 5, 2, 4, 4, 3, 4, 3, 4, 4, 5, 3, 4, 
    5, 5, 4, 5, 4, 5, 4, 5, 4, 5, 5, 5, 4, 5, 5, 5, 
    5, 5, 6, 5, 4, 5, 6, 5, 4, 5, 3, 5, 5, 4, 3, 4, 
    4, 4, 5, 4, 4, 5, 4, 5, 6, 5, 4, 5, 5, 4, 4, 5, 
    5, 5, 4, 5, 4, 5, 3, 5, 5, 
};

enum {
    CUBIES = 7,
    PERMUTATIONS = 5040,
    ORIENTATIONS = 729,
    STATES = PERMUTATIONS * ORIENTATIONS,
    MOVES = 9
};

typedef struct {
    uint8_t p[CUBIES], o[CUBIES];
} state_t;

/*@ predicate valid_state(state_t *state) =
      (\forall integer i; 0 <= i < CUBIES ==>
         state->p[i] < CUBIES && state->o[i] < 3) &&
      (\forall integer i, j; 0 <= i < j < CUBIES ==>
         state->p[i] != state->p[j]) &&
      (state->o[0] + state->o[1] + state->o[2] + state->o[3] +
       state->o[4] + state->o[5] + state->o[6]) % 3 == 0;
 */

static const uint8_t move_turn[9] = {1,2,3,1,2,3,1,2,3}; // turn = (move % 3) + 1
static const uint8_t move_face[9] = {0,0,0,1,1,1,2,2,2};  // move: 0,1,2 means quarter-turn on right face(0), 3,4,5 means on Back face(1), and so on, to do this, we prevent the face calculation(move/3)
static const char *const move_names[MOVES] = {"R",  "R2", "R'", "B", "B2",
                                              "B'", "D",  "D2", "D'"};
static const uint8_t inverse_move[MOVES] = {2, 1, 0, 5, 4, 3, 8, 7, 6};
/* Each destination takes a cubie from source[face][destination]. */
static const uint8_t source[3][CUBIES] = {
    {1, 4, 2, 0, 3, 5, 6},
    {0, 1, 2, 4, 5, 6, 3},
    {0, 2, 5, 3, 1, 4, 6},
};
static const uint8_t twist[3][CUBIES] = {
    {1, 2, 0, 2, 1, 0, 0},
    {0, 0, 0, 1, 2, 1, 2},
    {0, 0, 0, 0, 0, 0, 0},
};

/* The three quarter-turns preserve the fixed front-upper-left corner. */
/*@ requires face < 3;
    assigns \nothing;
    ensures \forall integer i; 0 <= i < CUBIES ==>
              \result.p[i] == state.p[source[face][i]];
    ensures \forall integer i; 0 <= i < CUBIES ==>
              \result.o[i] == (state.o[source[face][i]] + twist[face][i]) % 3;
 */
static state_t quarter_turn(state_t state, uint8_t face)
{
    state_t result;
    /*@ loop invariant 0 <= i <= CUBIES;
        loop invariant \forall integer j; 0 <= j < i ==>
          result.p[j] == state.p[source[face][j]];
        loop invariant \forall integer j; 0 <= j < i ==>
          result.o[j] == (state.o[source[face][j]] + twist[face][j]) % 3;
        loop assigns i, result.p[0..6], result.o[0..6];
        loop variant CUBIES - i;
    */
    for (uint8_t i = 0; i < CUBIES; ++i) {
        uint8_t from = source[face][i];
        result.p[i] = state.p[from];
        /* uint8_t sum = (uint8_t) ((state.o[from] + twist[face][i]));
        if(sum >= 3){   // use substraction to replace division.
            sum -= 3;
        }
        result.o[i] = sum;
        */
        int32_t diff = (int32_t)(state.o[from] + twist[face][i] - 3);         // diff = o' -3 , o' should be 0, 1, 2, if o' really < 3, o' - 3 will be a negative value(with MSB == 1), arithmetic right shift this bit 7bits will create an all-ones mask, if we bitwise and this mask & 3, it will output 0000011(3) then added to diff(o'-3) it wil return o'(already < 3), and vice versa, the mask will be all-zeros mask, mask & 3 == 0, it returns the o'-3+0 == o'-3 which is exactly what we should do when o' > 3
        int32_t mask = diff >> 31;
        result.o[i] = (uint8_t) (diff + (mask & 3));                                     
    }
    return result;
}

static state_t apply_move(state_t state, uint8_t move)
{
    uint8_t turns = move_turn[move];
    uint8_t face = move_face[move];
    for (uint8_t i = 0; i < turns; ++i){
        state = quarter_turn(state, face);
    }
    return state;
}

/*@ requires \valid_read(state);
    requires \forall integer i; 0 <= i < CUBIES ==>
      0 <= state->p[i] < CUBIES;
    requires \forall integer i, j; 0 <= i < j < CUBIES ==>
      state->p[i] != state->p[j];
    requires \forall integer i; 0 <= i < CUBIES ==>
      0 <= state->o[i] < 3;
    assigns \nothing;
    ensures \result < STATES;
 */

// replace whole block of rank_state(calc both p and o )
static uint16_t get_orientation_rank(state_t *state){
    uint16_t o=0;
    for(uint8_t i=0; i<6; ++i){        // bounded by 6 because the seventh orientation is strictly forced by first 6(invariant)
        o = ((o << 1) + o) + state->o[i];   // o * 3U is replaced by (o << 1) => 2*o + o => 3*o
    }
    return o;
}

static bool is_solved(state_t *state){
    for(uint8_t i=0; i<CUBIES; ++i){              
        if(state->p[i] != i || state->o[i] != 0){
            return false;
        }
    }
    return true;
}

// static uint32_t rank_state(const state_t *state)
// {
    // uint32_t p = 0, o = 0;
    /*@ loop invariant 0 <= i <= CUBIES;
        loop invariant (i == 0 ==> p == 0) && (i == 1 ==> p <= 6) &&
          (i == 2 ==> p <= 41) && (i == 3 ==> p <= 209) &&
          (i == 4 ==> p <= 839) && (i == 5 ==> p <= 2519) &&
          (i >= 6 ==> p <= 5039);
        loop assigns i, p;
        loop variant CUBIES - i;
     */
    // for (uint8_t i = 0; i < CUBIES; ++i) {
        // uint8_t smaller = 0;
        /*@ loop invariant i + 1 <= j <= CUBIES;
            loop invariant smaller <= j - i - 1;
            loop assigns j, smaller;
            loop variant CUBIES - j;
         */
        // for (uint8_t j = (uint8_t) (i + 1U); j < CUBIES; ++j)
            // if (state->p[j] < state->p[i])
                // ++smaller;
        // p = p * (CUBIES - i) + smaller;
    // }
    /*@ loop invariant 0 <= i <= 6;
        loop invariant (i == 0 ==> o == 0) && (i == 1 ==> o < 3) &&
          (i == 2 ==> o < 9) && (i == 3 ==> o < 27) &&
          (i == 4 ==> o < 81) && (i == 5 ==> o < 243) &&
          (i == 6 ==> o < 729);
        loop assigns i, o;
        loop variant 6 - i;
     */
    // for (uint8_t i = 0; i < 6; ++i)
        // o = o * 3U + state->o[i];
    // return p * ORIENTATIONS + o;
// }   


/*@ requires \valid(state); requires rank < STATES; assigns *state; */
/* static void unrank_state(uint32_t rank, state_t *state)
{
    uint8_t available[CUBIES] = {0, 1, 2, 3, 4, 5, 6};
    uint32_t p = rank / ORIENTATIONS, o = rank % ORIENTATIONS, f = 720;
    uint8_t sum = 0;
    for (uint8_t i = 0; i < CUBIES; ++i) {
        uint8_t q = (uint8_t) (p / f);
        p %= f;
        state->p[i] = available[q];
        for (uint8_t j = q; j + 1U < CUBIES - i; ++j)
            available[j] = available[j + 1U];
        if (i < 5)
            f /= 6U - i;
    }
    for (uint8_t i = 6; i-- > 0;) {
        state->o[i] = (uint8_t) (o % 3U);
        sum = (uint8_t) (sum + state->o[i]);
        o /= 3U;
    }
    state->o[6] = (uint8_t) ((3U - sum % 3U) % 3U);
}
    */

/*@ requires \valid_read(state);
    requires \initialized(&state->p[0..6]) && \initialized(&state->o[0..6]);
    assigns \nothing;
    ensures \result != 0 ==> \forall integer i; 0 <= i < CUBIES ==>
      state->p[i] < CUBIES && state->o[i] < 3;
    ensures \result != 0 ==> \forall integer i, j; 0 <= i < j < CUBIES ==>
      state->p[i] != state->p[j];
    ensures \result != 0 ==>
      (state->o[0] + state->o[1] + state->o[2] + state->o[3] +
       state->o[4] + state->o[5] + state->o[6]) % 3 == 0;
    ensures complete: valid_state(state) ==> \result != 0;
 */
static int valid(const state_t *state)
{
    uint8_t sum = 0;
    /*@ loop invariant 0 <= i <= CUBIES;
        loop invariant sum <= 2 * i;
        loop invariant sum == (i > 0 ? state->o[0] : 0) +
          (i > 1 ? state->o[1] : 0) + (i > 2 ? state->o[2] : 0) +
          (i > 3 ? state->o[3] : 0) + (i > 4 ? state->o[4] : 0) +
          (i > 5 ? state->o[5] : 0) + (i > 6 ? state->o[6] : 0);
        loop invariant \forall integer j; 0 <= j < i ==>
          state->p[j] < CUBIES && state->o[j] < 3;
        loop invariant \forall integer j, k; 0 <= j < k < i ==>
          state->p[j] != state->p[k];
        loop assigns i, sum;
        loop variant CUBIES - i;
    */
    for (uint8_t i = 0; i < CUBIES; ++i) {
        if (state->p[i] >= CUBIES || state->o[i] >= 3)
            return 0;
        /*@ loop invariant 0 <= j <= i;
            loop invariant \forall integer k; 0 <= k < j ==>
              state->p[k] != state->p[i];
            loop assigns j;
            loop variant i - j;
        */
        for (uint8_t j = 0; j < i; ++j)
            if (state->p[j] == state->p[i])
                return 0;
        sum = (uint8_t) (sum + state->o[i]);
    }
    while(sum >= 3){
        sum -= 3;
    }
    return sum == 0;
}



/* static uint8_t *build_table(uint8_t *diameter)                  // this is only run on host to get precomputed table which would be linked in as read-only data. So it's okay to have mul, div, mod operations.
{
    uint8_t *heuristic_distance_table = malloc((size_t)ORIENTATIONS * sizeof(uint8_t));  // or we can simply just write malloc(ORIENTATIONS)
    uint16_t *queue = malloc((size_t)ORIENTATIONS * sizeof(*queue));     
    uint16_t permutation[3][PERMUTATIONS], orientation[3][ORIENTATIONS];
    uint32_t head = 0, tail = 1, level_end = 1;
    state_t state;
    if(!queue){
        free(queue);
        return NULL;
    }

    for (uint16_t rank = 0; rank < PERMUTATIONS; ++rank) {
        unrank_state((uint32_t) rank * ORIENTATIONS, &state);
        for (uint8_t face = 0; face < 3; ++face) {
            state_t next = quarter_turn(state, face);
            permutation[face][rank] =
                (uint16_t) (rank_state(&next) / ORIENTATIONS);
        }
    }  // it's no use in our version
    for (uint16_t rank = 0; rank < ORIENTATIONS; ++rank) {
        unrank_state(rank, &state);
        for (uint8_t face = 0; face < 3; ++face) {
            state_t next = quarter_turn(state, face);
            orientation[face][rank] =
                (uint16_t) (rank_state(&next) % ORIENTATIONS);
        }
    }
    memset(heuristic_distance_table, UINT8_MAX, ORIENTATIONS);
    queue[0] = 0;
    heuristic_distance_table[0] = 0;
    *diameter = 0;
    while (head < tail) {
        if (head == level_end) {
            level_end = tail;
            ++*diameter;
        }
        uint16_t here = queue[head++];
        for (uint8_t face = 0; face < 3; ++face) {
            uint16_t next = here;
            for (uint8_t turn = 0; turn < 3; ++turn) {
                next = orientation[face][next];
                uint16_t there = next;
                if(heuristic_distance_table[there] == UINT8_MAX){
                    heuristic_distance_table[there] = (uint8_t) *diameter + 1U;
                    queue[tail++] = there;
                }
            }
        }
    }
    free(queue);
    if(tail != ORIENTATIONS){
        return NULL;
    }
    return heuristic_distance_table; // if we use uint8_t array(local variable) to declare heuristic table, we cannot use it to return to parent, which will cause "dangling pointer"(not "out of boundary use": this scenario when access the array with illegal index (greater/smaller than size/zero))
                                     // or we can declare it using 'static' array[] which will diminish the problem
}
*/

/*static uint8_t dfs_cost(state_t state, uint8_t g, uint8_t threshold, uint8_t *arr, uint8_t prev_move){
    // uint32_t rank = rank_state(&state);
    // uint16_t rank_o = rank % ORIENTATIONS;
    uint16_t rank_o = get_orientation_rank(&state);
    uint8_t h = heuristic_table[rank_o];
    bool solved = is_solved(&state);
    if(h==0 && solved){         // without this: when g+h == threshold which is not greater than threshold, and this state is with correct orientations but with wrong permutations, which we may get to solved state with at least one more step
        h = 1;                   // but in this time, we've already spend all of our budget(g == threshold), if we want to find a path get to solved state, we need more budget(higher threshold) ---> change the expected cost from 0 to 1, which will make condition below be true(<=> we shouldnt apply more move if we are out of budget)
    }
    if(g+h > threshold){         // cut off the path with expected distance greater than budget. ---> cut off the path with g(P) + h(P) > threshold.
        return g+h;
    }
    uint8_t min_pruned_threshold = UINT8_MAX;
    for(uint8_t move=0; move<9; ++move){
        if(g>0 && move_face[move] == move_face[prev_move]){
            continue;   // skip this move(iteration) if last move is on the same face ---> reduce calculations, because if it's on the same face, this 2 move can be combined into 1 move that the previous state can get to by taking another move generator.
        }
        state_t next_state = apply_move(state, move);
        // uint32_t next_state_rank = rank_state(&next_state);
        //if(next_state_rank == 0U){   // check whole part of state(including p and o), not just o, if it's zero then we solved the real rubik's cube!
            // found;
        //    arr[g] = move;
        //    return 0;
        //}
        if(is_solved(&next_state)){
            arr[g] = move;
            return 0;
        }
        uint8_t branch_threshold = dfs_cost(next_state, g+1, threshold, arr, move);    // write g+1 instead of ++g to prevent updating the g value used by succeeding iteration. Calculate the f-score of this child node, if it noticed that it's f-score(g+h) is greater than threshold , it returns directly. 
        if(branch_threshold == 0){   // those are not pruned
            arr[g] = move;
            return 0;
        }else{     // those are pruned  ---> minimum f-scroe(g+h) among them determines the next_threshold(if current threshold cannot get to goal)  
            //if(branch_threshold < min_pruned_threshold){
                //min_pruned_threshold = branch_threshold;
            // replace branch by masking like above(quarter turn).
            int32_t diff = (int32_t)branch_threshold - (int32_t)min_pruned_threshold;
            int32_t mask = diff >> 7;
            min_pruned_threshold = (uint8_t)(min_pruned_threshold + (diff & mask));  // if branch_thr really < min >>> this mask will be all one mask which let branch
        }
        // those are not pruned but cannot get to goal were ignored, they effect nothing.
    }
    return min_pruned_threshold;
}   */

/* static bool IDA_star(state_t *state){
    //uint32_t rank = rank_state(&state);
    //if(rank == 0){
        // print nothing
        //return true;
    //}
        
    if(is_solved(&state)){
        return true;
    }
    // uint16_t rank_o = rank % ORIENTATIONS;
    uint16_t rank_o = get_orientation_rank(&state);
    uint8_t h_state = heuristic_table[rank_o];
    uint8_t g_state = 0;
    uint8_t threshold = h_state + g_state;
    while(threshold <= 11){
        uint8_t path[threshold];
        uint8_t new_threshold = dfs_cost(state, g_state, threshold, path, 255);  // at the beginning solveing the cube, no previous move applied, give a ridiculous value in it, there will be no same move number with this at the first dfs_cost recurssion
        if(new_threshold == 0){
            // found
            for(int i=0; i < threshold; ++i){
                printf("%s ", move_names[path[i]]);
            }
            printf("\n");
            return true;
        }else{
            threshold = new_threshold; // else: cannot get to goal with that threshold ---> update threshold to chech if that budget is possible.
        }
    }
    return false;
}
    */
static bool IDA_star_iter(state_t initial_state){
    if(is_solved(&initial_state)){
        return true;
    }
    uint16_t rank_o = get_orientation_rank(&initial_state);
    uint8_t threshold = heuristic_table[rank_o];
    
    while(threshold <= 11){ 
        uint8_t depth = 0;
        
        state_t states[12];
        uint8_t moves[12];
        uint8_t min_pruned[12]; 
        
        states[0] = initial_state;
        moves[0] = 0;
        min_pruned[0] = UINT8_MAX;
        
        while(1){ 
            
            if (moves[depth] == 9) {
                if (depth == 0) {
                    threshold = min_pruned[0];
                    break; 
                }
                
                uint8_t current_min = min_pruned[depth];
                depth--; 
                
                int32_t diff = (int32_t)current_min - (int32_t)min_pruned[depth];
                int32_t mask = diff >> 31;
                min_pruned[depth] = min_pruned[depth] + (uint8_t)(mask & diff);
                
                moves[depth]++;
                continue;
            }
            
            uint8_t move = moves[depth];
            
            if (depth > 0 && move_face[move] == move_face[moves[depth - 1]]) {
                moves[depth]++;
                continue;
            }
            
            state_t next_state = apply_move(states[depth], move);
            uint16_t next_state_rank_o = get_orientation_rank(&next_state);
            uint8_t nxt_h = heuristic_table[next_state_rank_o];
            
            if(is_solved(&next_state)){
                for(int i = 0; i <= depth; ++i){
                    printf("%s ", move_names[moves[i]]);
                }
                printf("\n");
                return true;
            }
            
            if(nxt_h == 0){ 
                nxt_h = 1;
            }
            
            uint8_t nxt_f = (depth + 1) + nxt_h; 
            
            if(nxt_f > threshold){
                int32_t diff = (int32_t)nxt_f - (int32_t)min_pruned[depth];
                int32_t mask = diff >> 31;
                min_pruned[depth] = min_pruned[depth] + (uint8_t)(mask & diff);
                
                moves[depth]++; 
                continue;
            }
            
            depth++; 
            states[depth] = next_state;   
            moves[depth] = 0;             
            min_pruned[depth] = UINT8_MAX;
        }
    }
    
    return false;
}



/*@ requires valid_read_string(input);
    requires \valid(state);
    assigns state->p[0..6], state->o[0..6];
    ensures \result != 0 ==> input[14] == '\0';
    ensures \result != 0 ==> \forall integer i; 0 <= i < CUBIES ==>
      state->p[i] < CUBIES && state->o[i] < 3;
    ensures \result != 0 ==> \forall integer i, j; 0 <= i < j < CUBIES ==>
      state->p[i] != state->p[j];
    ensures \result != 0 ==>
      (state->o[0] + state->o[1] + state->o[2] + state->o[3] +
       state->o[4] + state->o[5] + state->o[6]) % 3 == 0;
    ensures \result != 0 ==> \forall integer i; 0 <= i < CUBIES ==>
      state->p[i] == input[i] - '1';
    ensures \result != 0 ==> \forall integer i; 0 <= i < CUBIES ==>
      state->o[i] == input[i + CUBIES] - '1';
 */
static int parse_state(const char *input, state_t *state)
{
    /*@ loop invariant 0 <= i <= 14;
        loop invariant i <= strlen(input);
        loop invariant i <= 7 ==> \initialized(&state->p[0..i-1]);
        loop invariant i >= 7 ==> \initialized(&state->p[0..6]);
        loop invariant i >= 7 ==> \initialized(&state->o[0..i-8]);
        loop invariant \forall integer j; 0 <= j < i && j < CUBIES ==>
          state->p[j] == input[j] - '1';
        loop invariant \forall integer j; 0 <= j < i - CUBIES ==>
          state->o[j] == input[j + CUBIES] - '1';
        loop assigns i, state->p[0..6], state->o[0..6];
        loop variant 14 - i;
     */
    /*for (int i = 0; i < 14; ++i) {
        int limit = i < 7 ? 7 : 3;
        if (input[i] < '1' || input[i] > '0' + limit)
            return 0;
        (i < 7 ? state->p : state->o)[i % 7] = (uint8_t) (input[i] - '1');
    }
    return input[14] == '\0' && valid(state);
    */
    for(uint8_t i=0; i<7; ++i){
        if(input[i] < '1' || input[i] > '7'){
            return 0;
        }
        state->p[i] = (uint8_t) (input[i] - '1');     // initially cubie numbers from 0 to 6;
    }
    for(uint8_t i=7; i<14; ++i){
        if(input[i] < '1' || input[i] > '3'){
            return 0;
        }
        state->o[i-7] = (uint8_t)(input[i] - '1');      // initially cube orientation from 0 to 2;
    }
    return input[14] == '\0' && valid(state);
}

/* stdout is fully buffered off a terminal, so a write error surfaces at the
 * flush, not at the printf that queued the bytes. Every exit path that has
 * produced output goes through here.
 */
static int output_failed(void)
{
    return fflush(stdout) != 0 || ferror(stdout);
}

/*static int self_test(void)
{
    const state_t solved = {{0, 1, 2, 3, 4, 5, 6}, {0}};
    state_t state;
    for (uint8_t move = 0; move < MOVES; ++move) {
        state = solved;
        state = apply_move(state, move);
        state = apply_move(state, inverse_move[move]);
        if (memcmp(&solved, &state, sizeof solved))
            return 0;
    }
    for (uint32_t rank = 0; rank < STATES; ++rank) {
        unrank_state(rank, &state);
        if (!valid(&state) || rank_state(&state) != rank)
            return 0;
    }
    return 1;
}
    */

int main(int argc, char **argv)
{
    state_t state;
    // uint8_t diameter;
    /* if (argc == 2 && !strcmp(argv[1], "--self-test")) {
        if (!self_test()) {
            fputs("self-test failed\n", stderr);
            return 1;
        }
        uint8_t *table = build_table(&diameter);
        if (!table) {
            fputs("could not build complete state table\n", stderr);
            return 1;
        }
        printf("const uint8_t heuristic_table[729] = {\n    ");
        for(int i = 0; i <729; ++i){
            printf("%d, ", table[i]);
            if(((i+1) % 16) == 0){
                printf("\n    ");
            }
        }
        printf("\n};\n");
        free(table);
        if (diameter != 11) {
            fputs("BFS check failed\n", stderr);
            return 1;
        }
        if(diameter < 11){
            printf("Heuristic distance table diameter: %d\n", diameter);
        }
    }
    */
    if (argc != 2 || !parse_state(argv[1], &state)) {
        /* C99 5.1.2.2.1 lets argv[0] be null when argc is 0. */
        fprintf(stderr, "usage: %s PPPPPPPOOOOOOO\n",
                argc > 0 && argv[0] ? argv[0] : "solver");
        return 2;
    }
    /*uint8_t *table = build_table(&diameter);
    if (!table) {
        fputs("could not build complete state table\n", stderr);
        return 1;
    }
        */
    bool solved = IDA_star_iter(state);
    if(solved){
        printf("A move sequence to solved state is printed.\n");
    }else{
        printf("Our IDA_star algorithm failed.\n");
    }
    // free(table);
    return output_failed();
}
