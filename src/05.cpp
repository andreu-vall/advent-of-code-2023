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
        //seeds[2*i] // range start
        //seeds[2*i+1] // range length
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
    //PER CADA TRANSFORMACIÓ
    for (int i = 0; i < 7; i++) {
        //vector<long long> newValues;
        //vector<bool> transfered(seeds.size(), false);
        getline(cin, line); // Ignore first line

        vector<long long> converted;

        //PER CADA REGLA
        while (getline(cin, line) && line.length() > 1) {
            //Ara hauré d'actualitzar els values en cada iteració
            //Tinc per una banda a les que ja sé que aplicaré i les pendents d'aplicar
            vector<long long> newValues;
            long long a, b, c;
            istringstream iss(line);
            iss >> a >> b >> c;
            for (int i = 0; i < values.size()/2; i++) {
                //He de separar entre els convertits i els no convertits
                //en un array seguiré tenint els pendents
                //i en un altre els convertits ja
                //Si el deixo igual el torno a posar a newValues
                //si el convertiexo el poso en converted
                //al final lo que queda en newValues tmb passarà a converted bastant
                //igual de com estava

                //Aquí tinc 2*i i 2*i+1 que són range start i range length
                //Pot ser que s'apliqui la regla a res, tot el rang, o només una part del rang
                //Per tant hauré de separar el rang en rangs més petits

                //Ara toca partir-ho...
                //values[2*i] // range start
                //values[2*i+1] // range length

                //La part on s'aplica el rang s'hauria d'afegir al array de convertits

                long long start = values[2*i];
                long long end = values[2*i] + values[2*i+1] - 1; // end is included in the range

                if (end < b || start > b + c) {
                    // Rule doesn't apply
                    newValues.push_back(start);
                    newValues.push_back(end - start + 1);
                } else {
                    // Rule applies to part or all of the range
                    if (start < b) {
                        // Part of the range before the source range
                        newValues.push_back(start);
                        newValues.push_back(b - start);
                    }
                    if (end > b + c) {
                        // Part of the range after the source range
                        newValues.push_back(b + c + 1);
                        newValues.push_back(end - (b + c) + 1);
                    }
                    // Part of the range within the source range
                    converted.push_back(a + max(0LL, start - b));
                    converted.push_back(min(c, end - b + 1));
                    cout << "Converted: " << a + max(0LL, start - b) << " " << min(c, end - b + 1) << endl;
                }
                //a destination range start
                //b source range start
                //c range length

                /*int seed = values[i];
                if (seed >= b && seed <= b + c && transfered[i] == false) {
                    newValues.push_back(seed + a - b);
                    //transfered[i] = true; //Només s'aplica la regla el primer cop que es compleix
                }*/
            }
            //he d'anar convering seeds -> soil -> fertilizer -> ...
            //destination range start, source range start, range length
            //50 98 2
            

        }
        cout << "Converted: ";
        for (long long value : converted) {
            cout << value << " ";
        }
        cout << endl;
        cout << "Unconverted: ";
        for (long long value : values) {
            cout << value << " ";
        }
        cout << endl;
        //Falta afegir directament a converted els que no s'han convertit
        for (long long value : values) {
            converted.push_back(value);
        }
        values = converted;
        cout << i << ": ";
        for (long long value : values) {
            cout << value << " ";
        }
        cout << endl;
        /*for (int i = 0; i < values.size(); i++) {
            if (transfered[i] == false) {
                newValues.push_back(values[i]);
            }
        }*/
        //values = newValues;
        /*for (long long value : values) {
            cout << value << " ";
        }
        cout << endl;*/
    }
    cout << "Part 1: " << *min_element(values.begin(), values.end()) << endl;
    cout << "Part 2: " << *min_element(values.begin(), values.end()) << endl;
}