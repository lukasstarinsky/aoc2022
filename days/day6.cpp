#include <fstream>
#include <string>
#include <unordered_map>
#include <iostream>

#include "days.h"

static int GetProcessedCharsAmount(int amount) {
    std::string test = "hjchjcjhjshjsssrfsrrldrddbrrzfzjzzrffvwwclwlffhwhwpwfffcbctbccchmccfmmwdmmdwwdttwffsfshswhhfchfchcphpnnflnlznlnnnvpnnhjhrrjgrglgwwrgghzhnzztlltbtwbbvmmzppdmmhchnccspccvmvwwzpwzzmddjmdmbdmmrzmmhlhhhdndllrlgrllmlhljlmmgdmggwdggffblbmmdgdwgdgwgvgcgtctjjnfnsffbqbwbnnsbbqsswggncgncntccqqfmmlqllllvrvlrlgldlggjvvqdvqvzvzpzrrvfvcfcqfcflfjfjrrwbrrpnrrvzzbddfdgfdgfddppbdbbjddtcdtccllvccjtctmccsttfcfppmvppbvpvjpvprvvmggjffbqbbqhbbcdbdrbrjrllgmggwdwzddzdczddgpgglgpgqgmgllrqlqmlqllmbmzmdzdbzddqbbzwwjfjqqlrrzgrrlzzdczddlflpfpqfqrqzzpdzdnznwwvjjnndldpdppfgppgwwnddmzzmffvgggphpbpnbblqbqccswwlcwlltvvlggqvqhvvtstmssbvvflvvhdhggqpgqgqlqggjvjpphhqnhqhvqhvqvpvvfvqfqvvbmbtmmqpqccwcbbqwbbmjbjsscsqqcccbjbvvmsmrmwrwwbhwwdpwphprptrrdssrprjrdrssqtqzqtzzcbbvrrpwrwlwbbpwwrddfcfccvttdsshqhqddsmslsffdsdrrswsmmztzhzghgqhqbbfcctmcmmdwwpbpdbbnjbnbmnmqqqftfdfnfzfqzffmmnqqgfgwwntnwwfsfmssnzzscsmmzttdwttfppnccngggmrmbmccrbcrclcslsfspfsswnwpwjwddbnbjbrjbrjbrjbrrlgljggcpgptpltlmlnnjpnptnppdcdwcwfcwcnnzddbrrnbnnsjsnjjjsqjjqhjjbrjbbghbgggsdshswsrwwqbwqqmtqmqdmdttwfwzztwztwtfwtwtfwwjpwjjljcccdbdndmmhjhzzszfssgbbwbhhhrhfrhhwttwltwtbwbrbqbpbwwjtwwdjjwhwmmddhgdhhhdrhrjjngjgnjnfjnjrjtrrhmmjzzsjzjhjmmvnmnqqzbbtnncffnhnhgnhggcssvrrwfwjwgjwwwdtwddgrrwnwffndnbdnbnsnbsnndtdvvdtdsdhshcczqzztzfzdzndnnhqqzggwrwtrtvtjvjvsjjzhzggtffdbbzwbbnwwnhnpnznfncnqqvmvbmbcbgcgfggtpggjqggnppwmwzzqpzzvvgqqjjhrrmmfsfvvbqvbqqptpztpzzhnndgngdngdngnllslhhsvssdffwllchlccjpjdpddgcgrgttmqttjlttphhdwdtdtnnrggmhhmhmgghnhbhppfmmlrmmlqqsllwswpsshbbfjjqvvlsvvblbljltjtjsszcscmsmgmddzsdddznnvvddwbwjwwmqwqlqvqffptfpttgngpgttlglpgppssthshwhzhshfshssstppbpjjtgjttlsszmzccrllwjjcdccgmccdppnlnrlltntcnttrhtrtqqfhhjfffldfdldbbqjqzzqjzzfhhtvvrrfqfsqfftrtbblmlsltsszqqcsshllvlbbpgpzgpgcppwnpwnwpnnjjmllrhllfzlzglzlnlrrcssjjjtgjgjjznjnmmjjpccqrqzrzzmfzfczcssnttddfjdfjfpjjmqjqnqtqbqzzqqzwwzwqqfccvcrvrqrlqrlqqnvjtqswzvngfcjpmnrnvnwtwnjvsmzhtwzpjbpglchwfvwhvznsvhvwwjppmqqpcpmzrznqrlvbgdfcpgdtfhwdclvzjqlhtbdvsgpjlrgbcjblnqhffbcjfwsgssfzlsbhrptfgsfsstzbwqcsrpgftblrnldhwfwpgpffftsjgclzqmjmcvwjrsbhgdblswrwnhpjtgsggmnjqgzzctjjztwhcqvhqfvddljjtqwgpmwdsmmhdttvdpqpvsqbpwmtzgfthtmfhmplmwqcbmdmrwqmmzmjmfdbqspmshlhtbmbcpcjsgdccwmbfwvftlshtrgzvbndqvqjzqgbgrnmzbwfgntfphjrvhrgzgdqclvpvwffghthlqwlghfqrwpdmgnthqwznqsjrnnpghfcfwctpvnbnftczlhmdslfvqprhgqmzmzsjvtzfsfzlcrltjhfgmwqcvnzmttfvvbsjslqfwmnhgbbjdwfgbzsjqfsgvphvmclfgtmcvlpslpqfsbzgccqslmrgdwrtlrzbbvrjrnnnncgrnsggzjrfqtmhjdvdfbwdmqrjbghrbnhpqcdzgbqwrvrcpwdlbvrdpfhnpbncjzgmftjhvwnplmnlfnlfjsjnqhtgqldzqlrlqtdjndjpsfdcdfrwtqblzpsqjvnqchdhwvswrmczhsbpfggsvzdznqjlrjjbcjnsjvqtrtttmmcgdwbqcthqvzffjmdbvjmjvcrmnpjgtjshbnlqpdfdnbcfmbrzsvqftrnfzmjdhpprpnwqbngmbbwjvmdzbwvttncdtgqnwwchmbbdtrwlflmqnbthnczfpmtpfpqpbwbcpsplgfpjfptdpvzjnbgzrfdwpdrztqtsrzmbfqhgwnfzcsbdsjsmbdghjcjlvbpjpplgqqnbqpqgsqqbmpgmlghrlbcfzjhlqfgdpfljspwqjbsjqzwwhrcpfrhwpvgrjpqjzfzphcrwbfwsjdsjtlwctsfhrmbnvsrfwwvgqtjtjvvqzjznlrsblgthjfrphsfmbtpmbthwdhrqbdmbzplbvpbcwvhgrsjccsnhbrqdbljzpdttbffqrbmgmzsmhdhsmnnmjqtwdjpmhlpwtwhvbfnjzfcwfzfplsbqgcvwgjcbwzbzmqdchwrggjwgjbttsttsztrftttqpslwvtcrjmdtwdhlwnhpjstqnqtvrmlmtcgjljzrthgpmvdjzlwfntqmbpdpgmmvvwqmdqqwrnlsrmhrpdtmhjrngwdfgddlrmdnfdnscjhdfjzwljjrsclnfdmhpbsvwtsmrdsvmpbjjpmmgtfclcccmcnzcslsvdwncrgtpvgbcgwdmcqlthgmrqmpnprlsqgzzpzzmhgflfgpjwgjjdpvggmhcstrwscqggqgrrjwtqzdfbnwgtvslvghfnzphbznqslcwwcsplgwjnltrttqzcvjhfdrwgjpclzmqfgvhzhrcdsgchhfqptqjwffmrsjrplzzlhnptwlmrvtstsrgnfdnrbtdbzjdcbthhtnjdprrpgtgfjsqnpgslcqgmdfpsrdfvhbqvvpthmmshpdnrrwlfcmqfbrsvqdqhffgbdhwjgcjsclcqpwnrfzfdqcvnmqnjmjnvhqmznmbnbnnjfrtlvbpdgglqpgcmqqcnpzfvvsnchpbjprpnwbdqvqzgjvgtnsrvswfmwhzllmlgpsglssnhcvbjtfghhrznpzntwwtnshmhhddnntdljhhhpmnchssqthbzpqmtmjbcfvmgnmwhpzrbwzzvzmnfdcsbvzphlglbhjpfmrtgfblhtszqvbbmtglwdhgjdvvgtpscgvwzjppfnlndnmtrnnnlfbgmrpqlvhvbgzmwghnsmdmdrftqpqncsbcmqhhhljzlwcrlsdbhrlddwlhcghvttjfsmfdzcllswjgsmcmghbflbdgpwfqplqnrvzfnctdsnmldhtbtpfrsztjdsgmnbrdjwbrgqlhdrlrnmlpwltgpwhwztbwpcqtwbqdmsfdfczftncvsggshhcqbjgcwjljcqdpczrnzbjhrhwcgrbbqzmmfjpqwrwppmnvcsfwprjqvtnzqzwtwlvvqssfjzbrvjjrmphtbjbrzttmvvhdfsnqdmpfbtprbqgzdgtjtpvbqqsgppsrnvsfnmgvbbsjcpttffthpvfjpnzmsjmpdzbldggtjrjqpshtmgpfgtcstdrgjhzjr";

    int processedChars = 0;
    for (int i = 0; i < test.length(); ++i) {
        std::unordered_map<char, bool> characters;

        for (int j = 0; j < amount; ++j) {
            if (characters[test[i + j]]) {
                break;
            }

            characters[test[i + j]] = true;

            if (j == amount - 1) {
                processedChars = i + j + 1;
            }
        }

        if (processedChars != 0) {
            return processedChars;
        }
    }

    return 0;
}

void Days::Run6() {
    std::cout << "Part 1: " << GetProcessedCharsAmount(4) << std::endl;
    std::cout << "Part 2: " << GetProcessedCharsAmount(14) << std::endl;
}