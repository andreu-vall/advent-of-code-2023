#include <iostream>
#include <sstream>
#include <vector>
#include <assert.h>
#include <bits/stdc++.h> 

using namespace std;

int main() {

    string line;
    getline(cin, line);

    vector<long long> seeds;
    stringstream ss(line);

    string seedString;
    getline(ss, seedString, ' '); // Ignore first word
    while (getline(ss, seedString, ' ')) {
        seeds.push_back(stoll(seedString));
    }
    assert(seeds.size() % 2 == 0);
    for (int i = 0; i < seeds.size()/2; i++) {
        seeds[2*i] // range start
        seeds[2*i+1] // range length
        //Per tant he de fer regles que treballin amb ranges enlloc de valors concrets
        //Per tant pot ser que per una seed s'apliqui la regla a una subsecció només i a la resta no
        //i a la resta s'aliqui alguna altra regla o cap
        //Per tant hauré de partir els rangs en rangs més petits cada cop pels llocs on s'apliqui la regla
        //i separar els llocs on no s'aplica per seguir aplicant més regles
        //Per tant hauré de treballar manualement amb els rangs jo mateix
        //Per tant en cada iteració hauré de tornar a deixar les seeds que no s'ha aplicat res i separar ja
        //de les que s'ha aplicat alguna regla
        //Això ho hauré de fer per cada regla tornar a generar un altre cop totes les no aplicades
    }
    getline(cin, line); // Ignore second line
    vector<long long> values;
    for (long long seed : seeds) {
        values.push_back(seed);
    }
    for (int i = 0; i < 7; i++) {
        vector<long long> newValues;
        vector<bool> transfered(seeds.size(), false);
        getline(cin, line); // Ignore first line
        while (getline(cin, line) && line.length() > 1) {
            //Ara hauré d'actualitzar els values en cada iteració
            //Tinc per una banda a les que ja sé que aplicaré i les pendents d'aplicar
            long long a, b, c;
            istringstream iss(line);
            iss >> a >> b >> c;
            for (int i = 0; i < values.size(); i++) {
                int seed = values[i];
                if (seed >= b && seed <= b + c && transfered[i] == false) {
                    newValues.push_back(seed + a - b);
                    transfered[i] = true; //Només s'aplica la regla el primer cop que es compleix
                }
            }
            //he d'anar convering seeds -> soil -> fertilizer -> ...
            //destination range start, source range start, range length
            //50 98 2
        }
        for (int i = 0; i < values.size(); i++) {
            if (transfered[i] == false) {
                newValues.push_back(values[i]);
            }
        }
        values = newValues;
        /*for (long long value : values) {
            cout << value << " ";
        }
        cout << endl;*/
    }
    cout << "Part 1: " << *min_element(values.begin(), values.end()) << endl;

}