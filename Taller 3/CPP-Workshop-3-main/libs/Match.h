    #ifndef MATCH_H
    #define MATCH_H

    #include <string>
    #include <sstream>
    #include "List.h"
    #include "TextFileHandler.h"

    using namespace std;

    struct Match {
        string localTeam;
        int scoreLocalTeam;
        string visitingTeam;
        int scoreVisitingTeam;

        int getPointsForLocalTeam() {
            if (scoreLocalTeam > scoreVisitingTeam) {
                return 3;
            } else if (scoreLocalTeam == scoreVisitingTeam) {
                return 1;
            }

        
            return 0;
        }

        int getPointsForVisitingTeam() {
            if (scoreVisitingTeam > scoreLocalTeam) {
                return 3;
            } else if (scoreVisitingTeam == scoreLocalTeam) {
                return 1;
            }

            return 0;
        }
    };

    Match getMatchFromLine(string line, char delimiter) {
            Match match;
            stringstream ss(line);
            string token;
            getline(ss, token, delimiter);
            match.localTeam = token;
            getline(ss, token, delimiter);
            match.scoreLocalTeam = stoi(token);
            getline(ss, token, delimiter);
            match.visitingTeam = token;
            getline(ss, token, delimiter);
            match.scoreVisitingTeam = stoi(token);
        
            
            
            
            
            return match;
    }

string getLineFromMatch(Match match, char delimiter) {
    string line;
    line = match.localTeam + delimiter + to_string(match.scoreLocalTeam) + delimiter + match.visitingTeam + delimiter + to_string(match.scoreVisitingTeam);
    


    return line;
}


     

#endif 