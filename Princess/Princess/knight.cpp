#include "knight.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
   std:: cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}
void inputline (int array[], string line, int &count){
    stringstream ss(line);
    while(ss>>array[count]){
        count++;}
}
void outputline (int array[], int &count){
	for (int i = 0; i < count; ++i){
	std::	cout <<array[i]<<" ";
	}
}
void stoi_numbers_of_n2(int n2, string numbers_of_n2, int array_of_n2[]) {
    int count_n2 = 0;
    stringstream ss(numbers_of_n2);
    string item;
    while (getline(ss, item, ',') && count_n2 < n2) {
        array_of_n2[count_n2] = std::stoi(item);
        count_n2++;
    }
}

void id_knight (int array[], int count,int &HP, int &level, int &remedy,int &maidenkiss,int &phoenixdown){
    for (int i = 0; i < count; ++i){
		switch (i){
		case 0: HP=array[i]; break;
		case 1: level=array[i];break;
		case 2: remedy=array[i]; break;
		case 3: maidenkiss=array[i]; break;
		case 4: phoenixdown=array[i]; break;
		}
	}

}
float baseDamage(int road_to_koopa, float &baseIndex) {
    switch (road_to_koopa) {
        case 1:
            baseIndex = 1;
            break;
        case 2:
            baseIndex = 1.5;
            break;
        case 3:
            baseIndex = 4.5;
            break;
        case 4:
            baseIndex = 7.5;
            break;
        case 5:
            baseIndex = 9.5;
            break;
    }
    return baseIndex;
}
void levelO(int round, int &level_competitor) {
    int b = (round + 1) % 10;
    level_competitor = ((round + 1) > 6 ? (b > 5 ? b : 5) : b);
}
int play_or_quit(int& remain_HP, int& rescue, int count2, int round) {
    if (remain_HP <= 0) {
        rescue = 0;
    }
    else {
        if (round == (count2 - 1)) {
            rescue = 1;
        }
        else{
            rescue = -1;
        }
    }
    return rescue;
}
int fight(int &level,int &level_competitor,int HP,int &remain_HP, int road_to_koopa) {
    if (level > level_competitor) {
        level++;
        if (level == 10)
            level = 10;
    }
    else if (level == level_competitor) {
        return remain_HP;
    }
    else if (level < level_competitor) {
        float baseIndex=0.0;
        baseDamage(road_to_koopa, baseIndex);
        remain_HP = remain_HP - (baseIndex * level_competitor * 10);
    }
    return remain_HP;
}
int phoenix(int& phoenixdown, int& remain_HP, int HP, int &rescue) {
    if (remain_HP <= 0) {
        if (phoenixdown == 0) {
            rescue=0;
        }
        else {
            phoenixdown--;
            remain_HP = HP;
            rescue=1;
        }
    }
    return rescue;
}
int remain_remedy(int HP, int& remain_HP, int& remedy, int &phoenixdown, int &rescue) {
    if (remedy >= 1) {
        remain_HP = remain_HP / 5;
        remedy--;
        remain_HP = remain_HP * 5;
    }
    else {
        remain_HP = remain_HP / 5;
        if (remain_HP <= 0) {
        phoenix(phoenixdown, remain_HP, HP, rescue);
        }
    }
    return remain_HP;
}
int shaman(int& level,int &level_competitor, int HP, int &remain_HP, int &rescue, int &remedy, int &phoenixdown, bool &tiny) {
    if (level > level_competitor) {
        level += 2;
        if (level >= 10) { level = 10; }
        rescue = 1;
    }
    else if (level == level_competitor) {
        rescue = 1;
    }
    else if (level < level_competitor) {
        remain_remedy(HP, remain_HP,remedy, phoenixdown, rescue);
        tiny = true;
    }
    return rescue;
}
int siren_vajsh( int &level, int& level_competitor, int& HP, int& remain_HP, int& remedy, int& maidenkiss, 
    int& rescue, bool &frog) {
    if (level > level_competitor) {
        level += 2;
        if (level >= 10) { level = 10; }
        rescue = 1;
    }
    else if (level == level_competitor) {
        rescue = 1;
    }
    else if (level < level_competitor) {
        if (maidenkiss >= 1) {
            maidenkiss--;
        }
        else {
            level  = 1;
            frog = true;
        }
    }
    return level;
}
bool isPrime(int& remain_HP) {
    if (remain_HP <= 1) {
        return false;
    }
    else {
        for (int i = 2; i * i < remain_HP; ++i) {
            if (remain_HP % i == 0) {
                return false;
            }
        }
    }
    return true;
}

int prime_num(int& remain_HP) {
    do {
        remain_HP++;
    } while (!isPrime(remain_HP));
    return remain_HP;
}
int mush_mario(int& level, int& phoenixdown, int HP, int& remain_HP) {
    int n1 = ((level + phoenixdown) % 5 + 1) * 3;
   // cout << "n1=" << n1;
    int s1 = 0;
    int num = 99;
    int two = -2;
    for (int i = 0; i < n1; ++i)
    {
        s1 += num;
        num += two;
    }
    std::cout << " s1=" << s1;
    remain_HP = remain_HP + (s1 % 100);
    //cout << " remain_HP = " << remain_HP;
    prime_num(remain_HP);
    if (remain_HP > HP) {
        remain_HP = HP;
    }
    return remain_HP;
}

bool isFibonacci(int& remain_HP, int fibo_num[]) {
    for (int i = 0; i < 16; ++i) {
        if (remain_HP == fibo_num[i]) {
            return true;
        }
    }
    return false;
}

void fibonacci(int fibo_num[]) {
    int num1 = 1;
    int num2 = 1;
    for (int i = 0; i < 16; ++i)
    {
        if (i == 0 || i == 1) {
            fibo_num[i] = num1;
        }
        else {
            fibo_num[i] = num1 + num2;
            num1 = num2;
            num2 = fibo_num[i];
        }
        std::cout << fibo_num[i] << " ";
    }
}

int mush_fibo(int HP, int& remain_HP) {
    int fibo_num[16];
    if (remain_HP == 1) {
        return remain_HP;
    }
    else {
        fibonacci(fibo_num);
        do {
            remain_HP--;
        } while (!isFibonacci(remain_HP, fibo_num));
    }
    return remain_HP;
}
// Sự kiện nấm ma
int type_of_mush_ghost(int round, int rounds_mush_ghost[], int &count_mush_ghost) {
    int i = 0;
    while (round > 0) {
        rounds_mush_ghost[i] = round % 10;
        std::cout << rounds_mush_ghost[i] << " ";
        round /= 10;
        i++;
    }
    std::cout << "Tong so: " << i << endl;
    // Tạo chuỗi nghịch đảo
    for (int j = 0; j < (i - 2) / 2; j++) {
        int temp = rounds_mush_ghost[j];
        rounds_mush_ghost[j] = rounds_mush_ghost[i - 3 - j];
        rounds_mush_ghost[i - 3 - j] = temp;
    }
    std::cout << "Challenges of mush ghost: ";
    for (count_mush_ghost = 0; count_mush_ghost < (i - 2); count_mush_ghost++) {
        std::cout << rounds_mush_ghost[count_mush_ghost] << " ";
    }
    std::cout << endl;
    return count_mush_ghost;
}

bool decrease(int n2, int array_of_n2[], int& mtx, int& mti) {
    for (int i = 1; i < n2; ++i) {
        if (array_of_n2[i] > array_of_n2[i - 1]) {
            return false;
            break;
        }
    }
    mtx = array_of_n2[0];
    mti = 0;
    return false;
}

bool mountain_peak(int n2, int array_of_n2[], int& mtx, int& mti) {
    int peak = 0;
    while (peak < n2 - 1 && array_of_n2[peak] < array_of_n2[peak + 1]) {
        mtx = array_of_n2[peak + 1];
        mti = peak + 1;
        peak++;
    }
    while (peak<n2 - 1 && array_of_n2[peak]>array_of_n2[peak + 1]) {
        peak++;
    }
    if (peak == n2 - 1) {
        return true;
    }
    else {
        return false;
    }
}
// Nấm ma loại 1
int mush_ghost_type_1(int n2, int array_of_n2[], int& remain_HP) {
    int mini = 0;
    int maxi = 0;
    int min, max;
    // Tìm số nhỏ nhất
    min = array_of_n2[0];
    for (int i = 1; i < n2; ++i) {
        if (array_of_n2[i] <= min) {
            min = array_of_n2[i];
            mini = i;
        }
    }
    std::cout << "mini= " << mini << endl;
    // Tìm số lớn nhất
    max = array_of_n2[0];
    for (int i = 1; i < n2; ++i) {
        if (array_of_n2[i] >= max) {
            max = array_of_n2[i];
            maxi = i;
        }
    }
    std::cout << "maxi= " << maxi << endl;
    remain_HP = remain_HP - (maxi + mini);
    return remain_HP;
}
// Nấm ma loại 2
int mush_ghost_type_2(int n2, int array_of_n2[], int& remain_HP) {
    int mtx = 0; // gtri đỉnh núi
    int mti = 0; // vị trí đỉnh núi
    decrease(n2, array_of_n2, mtx, mti);
    mountain_peak(n2, array_of_n2, mtx, mti);
    if (!decrease(n2, array_of_n2, mtx, mti) || !mountain_peak(n2, array_of_n2, mtx, mti)) {
        remain_HP = remain_HP - (mtx + mti);
    }else {
        remain_HP = remain_HP - (-2 - 3);
    }
    return remain_HP;
}
// Nấm ma loại 3
void tranfer_array_of_n2(int n2, int array_of_n2[]) {
    for (int i = 0; i < n2; ++i) {
        if (array_of_n2[i] < 0) {
            array_of_n2[i] = -array_of_n2[i];
        }
        else {
            array_of_n2[i] = (17 * array_of_n2[i] + 9) % 257;
        }
        std::cout << array_of_n2[i] << " ";
    }
    std::cout << endl;
}
int mush_ghost_type_3(int n2,int array_of_n2[], int &remain_HP){
	int maxi2=0;
	int mini2=0;
	
	// Tìm max
	int max2=array_of_n2[0];
	for (int i = 1; i < n2; ++i){
		if (max2<array_of_n2[i]){
			max2=array_of_n2[i];
			maxi2=i;
		}
	}
    std::cout<<"maxi2 = "<<maxi2<<endl;
	
	// Tìm min
	int min2=array_of_n2[0];
	for (int i = 1; i < n2; ++i){
		if (min2>array_of_n2[i]){
			min2=array_of_n2[i];
			mini2=i;
		}
	}
    std::cout<<"mini2 = "<<mini2<<endl;
	remain_HP=remain_HP-(maxi2+mini2);
	return remain_HP;
}
// Nấm ma loại 4
int mush_ghost_type_4(int n2, int array_of_n2[], int& remain_HP) {
    int max2_3x = array_of_n2[0]; 	// số lớn thứ 2
    int max2_3i = 0; 	// vị trí đầu tiên của số lớn thứ 2 trong 3 số đầu
    for (int i = 1; i < 3; ++i) {
        if (max2_3x > array_of_n2[i]) {
            max2_3x = array_of_n2[i];
            max2_3i = i;
        }
        else if (max2_3x == array_of_n2[i]) {
            max2_3x = -5;
            max2_3i = -7;
            break;
        }
    }
    std::cout << "max2_3x = " << max2_3x << endl;
    std::cout << "max2_3i = " << max2_3i << endl;
    remain_HP = remain_HP - (max2_3x + max2_3i);

    return remain_HP;
}
// Hàm hỗ trợ khi gặp Asclepius
bool take_the_pills(int take) {
    if (take >= 3) {
        return true;
    }
    return false;
}



int save_princess(int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue, int &remain_HP,
int road_to_koopa[], int count2,int n2, int array_of_n2[],int  array_asclepius_pack[][50], int r1, int c1, int plus_merlin) {
    int round_shaman = 0;
    int round_siren_vajsh = 0;
    int level_before_siren_vajsh=0;
    bool tiny = false;
    bool frog = false;
    int round_asclepius = 0;
    int round_merlin = 0;
    for (int round = 0; round < count2; round++) {
        int level_competitor;
        // is Athur
        if (HP == 999) {
            level++;
            rescue = 1;
            continue;
        }
        // is Lancelot
        if (isPrime(HP) == true) {
            if ((road_to_koopa[round]) > 0 && (road_to_koopa[round] < 8)) {
                level++;
                continue;
            }
        }
       
        if (road_to_koopa[round] == 0) {
            rescue = 1;
            break;
        }
        else if (road_to_koopa[round] <= 5) {
            levelO(round, level_competitor); // Tinh ra level_competior
            std::cout << "levelO=" << level_competitor << endl;
            fight(level, level_competitor, HP, remain_HP, road_to_koopa[round]);    // Tinh ra remain_HP
            std::cout << "remain_HP=" << remain_HP << endl;
            phoenix(phoenixdown, remain_HP, HP, rescue);
        }
        else if (road_to_koopa[round] == 6) {
            if (tiny == true) {
                continue;
            }
            else {
                round_shaman = round;
                levelO(round, level_competitor);
                std::cout << "levelO=" << level_competitor << endl;
                shaman(level, level_competitor, HP, remain_HP, rescue, remedy, phoenixdown, tiny);
            }
        }
        else if (road_to_koopa[round] == 7) {
            if (frog == true) {
                continue;
            }
            else {
                round_siren_vajsh = round;
                level_before_siren_vajsh = level;
                levelO(round, level_competitor);
                std::cout << "levelO=" << level_competitor << endl;
                siren_vajsh(level, level_competitor, HP, remain_HP, remedy, maidenkiss, phoenixdown, frog);
            }
        }
        else if (road_to_koopa[round] == 11) {
            mush_mario(level, phoenixdown, HP, remain_HP);
            std::cout << " remain_HP= " << remain_HP<<endl;
        }
        else if (road_to_koopa[round] == 12) {
            mush_fibo(HP, remain_HP);
            std::cout << " remain_HP= " << remain_HP<<endl;
        }
        else if (road_to_koopa[round] > 100) {
            int rounds_mush_ghost[100];// hiệp sĩ trải qua các ải nấm ma
            int count_mush_ghost = 0;
            type_of_mush_ghost(road_to_koopa[round], rounds_mush_ghost, count_mush_ghost);
            for (int challenge = 0; challenge < count_mush_ghost; challenge++) {
                if (rounds_mush_ghost[challenge] == 1) {	// nấm ma loại 1
                    std::cout << "Mush ghost type 1: " << endl;
                    mush_ghost_type_1(n2, array_of_n2, remain_HP);
                    std::cout << "HP = " << remain_HP << endl;
                }
                else if (rounds_mush_ghost[challenge] == 2) {	// nấm ma loại 2
                    std::cout << "Mush ghost type 2: " << endl;
                    mush_ghost_type_2(n2, array_of_n2, remain_HP);
                    std::cout << "HP = " << remain_HP << endl;
                }
                else if (rounds_mush_ghost[challenge] == 3) {	// nấm ma loại 3
                    std::cout << "Mush ghost type 3: " << endl;
                    tranfer_array_of_n2(n2, array_of_n2);
                    mush_ghost_type_3(n2, array_of_n2, remain_HP);
                    std::cout << "HP = " << remain_HP << endl;
                }
                else if (rounds_mush_ghost[challenge] == 4) {	// nấm ma loại 4
                    std::cout << "Mush ghost type 4: " << endl;
                    mush_ghost_type_4(n2, array_of_n2, remain_HP);
                    std::cout << "HP = " << remain_HP << endl;
                }
            }
        }
        else if (road_to_koopa[round] == 15 || road_to_koopa[round] == 16 || road_to_koopa[round] == 17) {
            if (road_to_koopa[round] == 15) {
                remedy++;
                if (remedy > 99) {
                    remedy = 99;
                }
            }else if (road_to_koopa[round] == 16) {
                maidenkiss++;
                if (maidenkiss > 99) {
                    maidenkiss= 99;
                }
            }else if (road_to_koopa[round] == 17) {
                phoenixdown++;
                if (phoenixdown > 99) {
                    phoenixdown = 99;
                }
            }
        }
        else if (road_to_koopa[round] == 19) {
            round_asclepius++;
            if (round_asclepius >= 2) {
                continue;
            }
            int take;
            for (int r = 0; r < r1; ++r) {
                take = 0;
                for (int c = 0; c < c1; ++c) {
                    if (array_asclepius_pack[r][c] == 16) {
                        if (take_the_pills(take) == 1) {
                            break;
                        }
                        remedy++;
                        take++;
                    }
                    else if (array_asclepius_pack[r][c] == 17) {
                        if (take_the_pills(take) == 1) {
                            break;
                        }
                        maidenkiss++;
                        take++;
                    }
                    else if (array_asclepius_pack[r][c] == 18) {
                        if (take_the_pills(take) == 1) {
                            break;
                        }
                        phoenixdown++;
                        take++;
                    }
                }
            }



        }
        else if (road_to_koopa[round] == 99) {
            if (isPrime(HP) == true) {
                if (level >= 8) {
                    rescue = 1;
                    continue;
                }
            }else if (level == 10) {
                rescue = 1;
                continue;
            }

        }
        else if (road_to_koopa[round] == 18) {
            round_merlin++;
            if(round_merlin < 2){
                remain_HP += plus_merlin;
            }else {
                continue;
            }
        }










        // Cụm lệnh bên lề
        std::cout << "Round " << round + 1 << ":" << endl;
        display(remain_HP, level, remedy, maidenkiss, phoenixdown, rescue);
        std::cout << endl;

        if (round == (round_shaman + 3)) {
            remain_HP = remain_HP * 5;
            if (remain_HP > HP) {
                remain_HP = HP;
            }
        }
        if (round == (round_siren_vajsh + 3)) {
            level = level_before_siren_vajsh;
        }

        play_or_quit(remain_HP, rescue, count2, round);
            if (rescue == 0) {
                break;
            }
    }
    return rescue;
}


void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
    ifstream read_file(file_input);
    string line1,line2,line3;
    int knight[5], road_to_koopa[100];
    int count1=0,count2=0;
    int remain_HP;
    rescue=-1;

    // Dòng 1
    getline(read_file,line1);
    inputline(knight, line1,count1);
    id_knight(knight, count1,HP, level, remedy, maidenkiss, phoenixdown);
    display(HP, level, remedy, maidenkiss, phoenixdown,rescue);
    remain_HP=HP;
    // Dòng 2
    getline (read_file,line2);
    inputline (road_to_koopa,line2, count2);
    outputline(road_to_koopa,count2);
    std::cout<<endl;
    // Dòng 3
    getline(read_file, line3);
    stringstream type_of_line3(line3);
    string mush_ghost, asclepius_pack, merlin_pack;
    getline(type_of_line3, mush_ghost, ',');
    getline(type_of_line3, asclepius_pack, ',');
    getline(type_of_line3, merlin_pack);
    // Xử lý file mush ghost
    string mush_ghost_file = mush_ghost;
    ifstream read_mush_ghost(mush_ghost_file);
    string str_n2, numbers_of_n2;
    getline(read_mush_ghost, str_n2);
    getline(read_mush_ghost, numbers_of_n2);
    //Output dòng 3
    std::cout << str_n2<<endl;
    std::cout << numbers_of_n2 << endl;
    // Chuyển đổi kiểu dữ liệu int to string
    int n2 = std::stoi(str_n2);
    std::cout << n2 << endl;
    int array_of_n2[100];
    stoi_numbers_of_n2(n2, numbers_of_n2, array_of_n2);
    
    // Xử lý asclepius pack
    ifstream read_asclepius_pack(asclepius_pack);
    string row1, col1;
    getline(read_asclepius_pack, row1); 
    getline(read_asclepius_pack, col1);
    int r1 = std::stoi(row1);
    int c1 = std::stoi(col1);
    std::cout << "String to int : " << r1 << "\t";
    std::cout << c1 << endl;
    
    int array_asclepius_pack[50][50];
    for (int r = 0; r < r1; ++r) {
        for (int c = 0; c < c1; ++c) {
            read_asclepius_pack >> array_asclepius_pack[r][c];
        }
    }
    // In ra mảng 
    for (int r = 0; r < r1; r++) {
        for (int c = 0; c < c1; c++) {
            std::cout << array_asclepius_pack[r][c] << "\t";
        }
        std::cout << endl;
    }

    // Xử lý Merlin_pack
    ifstream read_merlin(merlin_pack);
    string str_n9;
    int plus_merlin = 0;
    getline(read_merlin, str_n9);
    int n9 = std::stoi(str_n9);
    for (int i = 0; i < n9; i++) {
        string item_merlin;
        getline(read_merlin, item_merlin);
        if (item_merlin.find("merlin") != string::npos || item_merlin.find("Merlin") != string::npos) {
            plus_merlin += 3;
        }else {
            string lowercase = item_merlin;
            for (char& c:item_merlin) {
                c = ::tolower(c);
            }
            if (lowercase.find("merlin") != string::npos) {
                plus_merlin += 2;
            }
        }
    }




    


  
    // Giải cứu công chúa
    rescue = save_princess(HP, level, remedy, maidenkiss, phoenixdown, rescue, remain_HP, road_to_koopa, count2, 
        n2,  array_of_n2,  array_asclepius_pack, r1, c1, plus_merlin);
    std::cout << endl;
    std::cout<<"After Saving the princess:"<<endl;
   display(remain_HP, level, remedy, maidenkiss, phoenixdown,rescue);
   
}

