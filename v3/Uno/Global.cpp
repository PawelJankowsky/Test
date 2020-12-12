#include "Global.h"

using namespace std;

Global::Global()
{
}


void Global::clearScreen()
{
	system("CLS");
	cin.clear();
}

void Global::intro()
{
	string unoText = R"(
ddddddddddddhhhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyysssssssssssssssssssssooo+++++ooooosssssssssssssssssssssyssyyyyyyyyyyyyyyyyyyyyyyysssyyyyyyyyyyyyyyyyyyyyyyyhhhyyyhhhhhhhhhhhyyhhhhddddhhhhhhhhh
dddddddddddhhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyssssssosssssssssssssoooo+++++oooosssssssssssso/::/ossssssssso+/:---:ossssssssssssssso+ooossyyyyyyyyso/:---syyyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
dddddddddhhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyyyyo/ssssssoo+osssssssssooooo++++oooooooooooooooso+:.  ```.++//:-.`````.-````osssssssssssssssoo+++osssso+/::/:://:`+yyyyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
dddddhhhhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyyys++oosssssooossssssssooooo+++ooooooooooooooooo+:-``````` ..    ````          `....----:::://+sssoososso-/://-/++++/./yyyyyyyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
ddddhhhhhhhhhhhhhhhyyyyyyyyyyssyyyyyyyyyyyyyo/+yyosossssssssssssooooooooooooooooooo+///so/-`     ``.-/+s  `smNNNmhdmdddhhyysssoo+++///:-`  `+ssssossso:::::/+/++++.:syyyyyyyyyyyhhhhhhhhyhhhhhhhhhhhhhhd
ddddhhhhhhhhhhhhhhyyyyyyyyyysssyyyyyyyyyys+/+oooossosssssssssoooooooooooooooooooo/.``.-.   .:/osyhhhhhhy  yMMMy++o+sMMMMMMMMMMMMMMMMMMMMN+  .ssssssssso/:-::+.:+++/.-osyyyyyyyyyyyyhhhhhyhhhhhhhhhhhhhhh
ddhhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyo/:syyyyssssssssssssooooooooooooooooooo+:..`   :`  /yyhhm:./hhhdo  mMm/oyyyy:NMMMMMMMmhso+//+oymMMN- -soossssssso/-::/:-////-:.+ssyyyyyyyyyyyyyyyyyhhhhhhhhhhhhhh
dhhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyys:/+syyyssosysosssssooooooooooooooooooo+-``   `../-  yhhyh/`oyhhhd+ `Nm-/+oyy/yMMMMNh+::/osssyss+-:dN. :sooooooooooo+:::::/:/-:+/.+ssyyyyyyyyyyssyyyyyhhhhhhhhhhhhh
hhhhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyys-s+yyyyossssoosssoooooooooooooooooo+/.   `.-----:/  +hhym/+-hhhhd: .Ns.-:so/yMMMd+:/oyyyyyyyyhhhyo.o` /ooooooooooooo+:-::::-://:/.:osssyyyyyo://:::/+osyhhhhhhhhhh
hhhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyyyyyy+/soyyyssssosssssssoooooooooo:.`./:`  `.://-/:---+. .hym+:.shhhhs. :Md:-++smMNy:/oyyyyyyyyyyhhhhhho   +oooooooooooooo+/-----::::::./ooossyy+:s++ssso+/::::/ooyhhhh
hhhhhhhhhyyyy+-.-:+osyyyyyyyyyyyyyyssss/ssossssosssssssooooooooooo-`..`-`  `:y:/o:/:---:/  oym+/odyhy:/` /MMNmNNMMy:/syyyyyyyyyyyhhhhhhhh-  ooooo++ooooo+oo++/+++ooooooooosoooss//os+sssoooooooo+/:`./yh
hhhhhhhhyyyy+ `----..-:/+osyyyyyssssosso+ysssssssssssooooooooooo+...` .+s` `-oo/o//:----+` -hhhhhhhh--h` oMMMMMMh:/syyyyyyyyyyyyhhhhhhhhh:  o+++++ooo+++++++//++oooooooooosso++:+ooo+++ossssso+:oyy- .yh
hhhhhhyyyyyo``/s+/:::::::::/++oyssssosss+ssssssssssoooooooooooo+.`  .+ssys` `---+o.+------ `shhhhhh:.yh  sMMMMN+:oyyyyyyyyyyyyyhhhhhhhhhh: `o+oo++++++++++++///++ooo+oo++osos/:/++oossyyyyyyyyys-+/`-yhh
hhhhhyyyyys.`:s:+://::::////+/+yssssssssooossssssoooooooooooos/` `-ossyssys` `---h/s---.`+  /hhhhh/`shy  hMMMm++yyyyyyyyyyyyyhhhhhhhhhhhh- .ohddhs++++++++++::/++++++o+/+oso/:/+oos+oo/yyyyyyyyy:``/yhhh
hhhhyyyyyy- -:/+/::::///+++//+syssssssssssssssssoooooooooooo/. `/oss/+:sssys` `--:/:---``+- `yhhho`ohdy:/hdhhyyyyyyyyyyyyyyyyyyyhhyysssss` -sddhhh+++++++++/::+++++++o//+oo//+ooosso--oyyyyyyyyo``+yhhhh
hhhyyyyyy/ -::--:///+++++++++sysssssssssssssssooooooooooooo.  -sssss+m:/hssy:` `------. `:+  +hhh/ohyyyyyyyyyyyyyyyyyyyyyyyyys+/:/++++++/-`./oyys+++++++++/::///++++++:/o+/+++oooos/:syyyyyyyy+..oyyyyyh
hhyyyyyy+`.---:+s//+//o++++osyysssssssssssssooooooooooooos+   /ssysshh:/+od/.s` `.----. .-+../hhyyyyyyyyyyyyyyyyyyyyyyyyyys+:/+o+/:-----:/oo+:-:/++++++////-:///+///+/:+//++++oooo::sysyyyyyo:`-syyyyyhh
hhhyyhhs``.-::/ooso+++o+++osyyssssssssoossooooooooooooooo-./. `+sh/:hss+yyy:`hy` `.---.`:/sssyyyyyyyyyyyyyyyyyyyyyysyyyyo::os/--......-....-:+s/.:+++/////:-///++//+/-://++++ooos++ssssyyso:.`:syyyyyyyh
hhyyhhy.`.:::+s:oss/+o+++osyysssssssssoosoooooooooooooo+. .sy/` -yyhhssysss:`yyy` `.--:/syyyyyyyyyyyyyyyyyyyyso+///-/ys::yy:....-..----.......-+s:.//////:-:////////-://+/+++oooossssso++/+-./syyyyyyyyh
hhhhhy:`-:::/+y+++++++++ossysssssssssssoosso+ooooooooo/` :syyys- `/ssssssss:`ssyy. -+syyyyyyyyyyyyyyyyyyyyo/:/++o++h.:-sNs......:ohdmmmdy/-.-...-so./////-:////////--///++/+++++ooo++++oso-.+ssyyyyyyyyy
hhhhh/`-:::///++++++oooossssssssssssssooosooooooooooo: `/yyyyyyyo. .+ssssss+ ossyh+syyyyyyyyyyyyyyyyyyyyo:/ym+:-...os:mMh.-....sNMMMMMMMmdh/.-..-.so.///--////////:-/++///+++++++ooossss+--ossyyyyyyyyyy
hhhho``-:::////+++ooooosssssssssssssosssoooooooooooo- .oyssyyyyyyy/ `:osssso`+yyhhyyyyyyyyyyyso+//osyyy-:hdhdh.-..-.yNMM-...-.yh+//+sdNdhhhN+.-....d:-/--////////--///+++//+ooooo+ossss/-:ossssyyyyyyyyy
hhhs`.---::///+++oooosssssssssssssssssssoooooooooo+. `syh+`-/syyyyh/. `/ssss.:hyyyyyyyyyso+///++oo+::os-/NhhhNs.-.-..mMN`-....m`/sss+:/dddNNN:...-.+y`:-///////:--/+/+++////+ooo++ssss/-/oosssssyyyyyyyy
hhh+--://+++oooosssssssssssssssssssssssoooossoooos-  -yyho+ho::/hyy+:/` -osyosyyyyyso////+yh+/:-.-:+o+:: smdNmN/.....:Nm`-..-.m./yyyyy/.dNddNs.-...-d`////////:--/////////++//oo+osso/:/oossssssyyyyyyyy
hhhhyyyyyyyyyyyyysssssssssssssssssssssoooossooooos+`  :oyhhyyhysdyyy-:s: `+yyyyys/:/+oo+/-hM+.-.....-:+o/:dNddNm-...-.oN-.---.os.syyyyy:-NmMMs.-.-.:d`+//////:-://///////++++//+osso::+oossssssssyyyyyyy
hhhhhhyyyyyyyyyyysyyysyssssssssssssssoooossoooooooso/-``.:osyyyyyyyys`/y+.oyyys/-+dmy.....-mN-.-.......-:+yNNMMMh.-..-.yy.-..-.so-+syyyo`mMMm-...-.os.+////:--:::///////+++++++/+++//+oosssssssssyyyyyyy
hhhhhyyyyyyyyyyyyyyysyyssssssssssssssoossssooooooooooso+-``.:osyyysso-.///-syy--mdhhm/.---.:Nd...--...-.-..:odNMMs.-....d+.-..-./s/:///:/Nmy-.-.-.-d./+///:--://:///////++++++//////+ooosssssssssyyyyyyy
hhhhhyyyyyyyyyyyyyyyyysssssssssssssssoossssoooooooooooooso+-``.:+://+oo+:h/-yy+`hmhdmm-...-.+My.-..-`::..-....:ohm/.-...:ms-.....-:++oooo/-....-.:h-:+///--:://////////++++++//////+oooosssssssssyyyyyyy
hhhhhyyyyyyyyyyyyyyyso+///+osssssssssssosssssooooooooooooooo+/.`/hNy-....-h./yy/.mmNmmh.-..-.yM+.-...:dh+-....-..:+`.-.-.oMd/-..-.-............-oy-/o/::--://///////////+++/:-::::+ooooossssssssssyyyyyy
hhhhhhyyyyyyyyyyso//:/++++/:/+ossssosssssssssssoooooooooooo+/--hMMMN:...-./y`oyy-:NdmMMs.-....mN:.-.-.+MMNh+-....-...-..-.yMMd+:-...........-/sdo:++/:--:://///:::///////:-::/++++::/+oossssssssssyyyyyy
hhhhyhyyyyyys+/::/+oo//+oooo++//+oossssssssssssoooooooooooooo+.dMMMMm.-..-.so.sys.oMMMMN/.-.-.:Nd...--.yMMMMNh+-..-.-......mMMMNdyo/::::/+shmmy/oo+:--://////////////:--:+ss+o//++/+ss+///oossssssyyyyyy
hhhhhhyyso:::/+ssss+-ossssoooooo+/:/+ossssssssssssoooooooooooy/-NMMMMy.-..-.h:-yyo`hMMMMm-..--.oMy.-..-.dMMMMMMNh+-....-.-.:NMMMMMMMMMMMMMNdo/+o+/--:/://////////:--:/ossssyyyyso+osdmmNdhs+//+ossyyyyyy
yyyhy+:--/o++o:o/ys.+sssssssooooooo+:://oosssssssssooooooooooos-+MMMMM+.--..-d./yy/.mMMMMh.-..-.dM+.-...:NmNMMMMMMNh+--...-.sNdmmNNNNmmhs+/+oo/:--://::////:/:-..-://:--.--:::-```````.-:/oyddyo/:/oyyyy
yyyy+` .syy-s//y:ss.ossssso/:/-://+oo//+///+oossssssooooooooooss.yMMNdm:...-.+y`oyy-/NMMMM/.-.-./MN:.-.-.+y-odNMMMMMMNh+/oydd+./:://///+osso+:--://://///:-.```..-:/::--/ossssso+-.:+-.``   `:dMN+ `oyyy
yyyhhs+-.-+ssossyys.+sssyo`+yh.:yo:/oo+:+oo+///+osssooooooooooos+.mmhhdd....-.so.sys.sMMMMo.-....MMd....-.y+`::odNMMMMMMMNmo-/syyyyyyyys++/:--://///:::-`````.-///////+ssssyyyyysys/-------   :y:`:oyyyy
yyhhhhhys+..-+ssyyy+.sssys`+sh.-ys/.sooo:+ooo++///+ooooooooo+/osy::NhhdNy.-....y+-+s/.NMMm-...-.-MMMy.-....d-:s+::odNmhs+::+syyyyyyyyso+/:--://::/:-.-:.````:o+//////++yhyysssyyyho-----:.`   `./oyyyyyy
hhhhhhhhhyys/..-+syy:-ssshy/:/..+::oyoooo:+o:+:+/o+-:oooooooooooss.+NNmdNo.-..-.+s+/:/mdo-......hMMMM+.:/oyd+`syyy+:::/osyyyyyyyyyyyo+::-:////:-.`:osy/```` ``-/o+/:.-yhyyyyyyyo/+o+::-.```  ./syyyyyyyy
hhhhhhhhhyyyyyo/.`-+s:-sssyhhysssyyyssooo/:o++:/:o+-:ooooooooooooss.ymdNMMo..-.-..-:/:-...-...-sdMMMMNmMMNs-/syyyyyyyyyyyyyyyyyyyyo+::-://////-``.ohhhy/.``            .:oyso/.   `.-:+o+.`-+ssyyyyyyyyy
hhhhhhhhhhyyyyyyso:.`--.+sssssssssssssssoo-oooooo:-/+ssooooooooooos+.dMMMMMh:...-...........-os-.mMMNmho/-/syyyyyyyyyyyyyyyyyyys+/::://////+++/:-``-+ydmdhs+/:-...``````...-:/+syhmNNm+``:osssyyyyyyyyyy
hhhhhhhhhhyyyyyssyyyo:.``-ossssssssssssss+-oooo+--+ssssoooooooo+oosy+.hMMMMMMh+:.......--/shy::o:-o/::/osyyyyyyyyyyyyyyyyyyyys+/:://++///+++++++/::-``-ohmNNNNMMNNdyyhdNMMMMMMMMMMNh- ./ssssssyyyyyyyyyy
hhhhhhhhhhyyyyyssyyyyyyo:.`-+ssssssssssso::sso:.:osossss+/ossoooooosys-omMMMMMMMmdhyhhdNNNy::oyyyoosyyyyyyyyyyyyyyyyyyyyyys+//://++///++++++++++//++/:.``-odNMMNho/-:hyhmmNMMMMMNo. ./ossssssyyyyyyyyyyh
hhhhhhhhhhyyyyyssyyyyyyysso:.`:+ossssso+-/ss+-./ssssssssssoosoooooooosy+-+dNMMMMMMMMMNmy+-/syyyyyyyyyyyyyyyyyyyyyyyyyyyso/////+++//+++++++++++++++++///:-.``-odmho+yoos/+modMMd/``:+oooossssyyyyyyyyyyyh
dhhhhhhhhhysssyyyyyyyyyyyyyyyo:.``.:::/+oss:.-ossssssssossssoo/+oooooosyhs/:/+ossso+/::+syyyyyyyyyyyyyyyyyyyyyyyyyyso+/////+++//++++++++++++++++++/////::///-``-odNMNhsyshyds- `:osssssssssyyyyyyyyyyyhh
ddhhhhhhhhhyyssyyyyyyyyyyyyyyyyso:``:+sss+.`:ssssssssossssoossosoooooooossyyyyssssssyyyyyyyyyyyyyyyyyyyyyyyhyyyso++////+/++++++o+++++++++++++++///:::://+ooooo/-``.+dNNNNd+` ./ssssssssssssyyyyyyyyyyyyh
dhdhhhhhhhhhyyyyyyyyyyyyyyyyyyyyyyo/:`````.+syssssssssssosssssssssssssoooooossssssyyhhhhhhhhhhhhhhhhhyyyysso++//:///+++++++oooooo+++ooo+++++++/:--:///+oooooooooo+-` ```   -+sssssssssssssssyyyyyyyyyyyy
ddddhhhhhhhhyysssyyyyyyyyyyyyyyyyyyyss+/::oyyyyyssssssssssssssso+++ssssssoooooooooooooosssossssssoooo++++////////+++++++ooooooooo++ooo++++++++:---/+ooooooooosssssso+::::/osssssssssssssossssyyyyyyyyyyy
dddddhhhhhhhyysssyyyyyyyyyyyyyyyyyyysssssosyyyyyyysssssssssssso/++ossssssssoooooooooooooo+++++/++++/////////++++++++ooooooooooooo++oo++++++++///++oooossssssssssssssssssooosssssssssooooossyyyyyyyyyyyyh
      
)";

	int i = 0;
	while (unoText[i] != '\0')
	{
		cout << unoText[i];
		Sleep(.5);
		i++;
	}


	string nameText = "Jankowski Pawel CP3";
	int j = 0;
	while (nameText[j] != '\0')
	{
		cout << nameText[j];
		Sleep(100 + rand() % 100);
		j++;
	}

	Sleep(3500);
	system("CLS");
}


Global::~Global()
{
}
