#include "Score.hpp"
Score::Score(){
    src = {1200, 866, 300, 45};
    mover = {0, 0, 40, 36};
    gap_x = 5;  gap_y = 3;
    score_vector.push_back(0);
    Pair pair;
    pair.src = {707, 899, 83, 99};      pair.mvr = {gap_x+0, gap_y+0, 30, 30 };
    score_src_mvr_vector.push_back(pair);
}
void Score::display(SDL_Renderer* renderer, SDL_Texture* assets){
    mover.w = (score_vector.size()*30) + (gap_x*2);
    SDL_RenderCopy(renderer, assets, &src, &mover);
    int size = score_vector.size() - 1;
    for (int i=size; i>-1; i--){
        // std::cout << "index: " << i << " element: " << score_vector[i] << '\n';
        SDL_Rect temp_src = (score_src_mvr_vector[i]).src, temp_mvr = (score_src_mvr_vector[i]).mvr;
        SDL_RenderCopy(renderer, assets, &temp_src, &temp_mvr);
    }
}

void Score::increment(){
    int size = score_vector.size();
    int i = 0;

    if (score_vector[i] < 9){
        score_vector[i] += 1;
    }
    else {
        while(score_vector[i] == 9){
            score_vector[i] = 0;
            if (i+1 == size){
                score_vector.push_back(1);
                Pair temp;
                score_src_mvr_vector.push_back(temp);
            }
            else{
                if (score_vector[i+1] != 9){
                    score_vector[i+1] += 1;
                    break;
                }
            }
            i++;
        }
        set_mvr_src();
    }
}

void Score::set_mvr_src(){
    int gap = gap_x;
    for (int i=score_vector.size()-1; i>-1; i--){
        if (score_vector[i] == 0){
            (score_src_mvr_vector[i]).src = {707, 899, 83, 99};
            (score_src_mvr_vector[i]).mvr = {gap+0, gap_y+0, 30, 30 };
        }

        else if (score_vector[i] == 1){
            (score_src_mvr_vector[i]).src = {811, 900, 47, 97};
            (score_src_mvr_vector[i]).mvr = {gap+0, gap_y+0, 30, 30 };
        }

        else if (score_vector[i] == 2){
            (score_src_mvr_vector[i]).src = {887, 900, 67, 97};
            (score_src_mvr_vector[i]).mvr = {gap+0, gap_y+0, 30, 30 };
        }

        else if (score_vector[i] == 3){
            (score_src_mvr_vector[i]).src = {972, 899, 67, 99};
            (score_src_mvr_vector[i]).mvr = {gap+0, gap_y+0, 30, 30 };
        }

        else if (score_vector[i] == 4){
            (score_src_mvr_vector[i]).src = {1052, 900, 79, 97};
            (score_src_mvr_vector[i]).mvr = {gap+0, gap_y+0, 30, 30 };
        }

        else if (score_vector[i] == 5){
            (score_src_mvr_vector[i]).src = {715, 1008, 68, 97};
            (score_src_mvr_vector[i]).mvr = {gap+0, gap_y+0, 30, 30 };
        }

        else if (score_vector[i] == 6){
            (score_src_mvr_vector[i]).src = {799, 1007, 70, 99};
            (score_src_mvr_vector[i]).mvr = {gap+0, gap_y+0, 30, 30 };
        }

        else if (score_vector[i] == 7){
            (score_src_mvr_vector[i]).src = {885, 1008, 69, 95};
            (score_src_mvr_vector[i]).mvr = {gap+0, gap_y+0, 30, 30 };
        }

        else if (score_vector[i] == 8){
            (score_src_mvr_vector[i]).src = {969, 1007, 74, 98};
            (score_src_mvr_vector[i]).mvr = {gap+0, gap_y+0, 30, 30 };
        }

        else if (score_vector[i] == 9){
            (score_src_mvr_vector[i]).src = {1056, 1007, 70, 98};
            (score_src_mvr_vector[i]).mvr = {gap+0, gap_y+0, 30, 30 };
        }
        gap += 30;
    }
}
