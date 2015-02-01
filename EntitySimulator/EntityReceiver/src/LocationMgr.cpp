#include "Mgr/LocationMgr.h"
#include <time.h>

// ÁÂÇ¥
const int maxidx = 20;
POS	  m_PosArray[maxidx][5];
bool	  m_flag[maxidx];
POS		  m_Pos[maxidx];
POS		  m_Start[maxidx];
POS		  m_End[maxidx];
int m_idx[maxidx];
void InitOwnshipXY()
{
	for(int i = 0; i<maxidx; ++i){
		m_idx[i] = 0;
	}
	m_PosArray[0][0].x = 127.677303;
	m_PosArray[0][0].y = 34.067334;

	m_PosArray[0][1].x = 127.879532;
	m_PosArray[0][1].y = 33.983342;

	m_PosArray[0][2].x = 127.953327;
	m_PosArray[0][2].y = 33.842408;

	m_PosArray[0][3].x = 127.770253;
	m_PosArray[0][3].y = 33.773337;

	m_PosArray[0][4].x = 127.642863;
	m_PosArray[0][4].y = 33.911139;

	m_PosArray[1][0].x =127.388839;
	m_PosArray[1][0].y = 33.704588;

	m_PosArray[1][1].x = 127.245325;
	m_PosArray[1][1].y = 33.785558;

	m_PosArray[1][2].x = 127.108371;
	m_PosArray[1][2].y = 33.705106;

	m_PosArray[1][3].x = 127.172702;
	m_PosArray[1][3].y = 33.551116;

	m_PosArray[1][4].x = 127.361067;
	m_PosArray[1][4].y = 33.581545;

	m_PosArray[2][0].x = 126.089204;
	m_PosArray[2][0].y = 33.722620;

	m_PosArray[2][1].x = 125.895422;
	m_PosArray[2][1].y = 33.753981;

	m_PosArray[2][2].x = 125.936789;
	m_PosArray[2][2].y = 33.613315;

	m_PosArray[2][3].x = 126.128515;
	m_PosArray[2][3].y = 33.606473;

	m_PosArray[2][4].x = 126.281168;
	m_PosArray[2][4].y = 33.681478;

	m_PosArray[3][0].x = 124.961301;
	m_PosArray[3][0].y = 33.637890;

	m_PosArray[3][1].x = 124.766888;
	m_PosArray[3][1].y = 33.603135;

	m_PosArray[3][2].x = 124.692855;
	m_PosArray[3][2].y = 33.440337;

	m_PosArray[3][3].x = 124.928129;
	m_PosArray[3][3].y = 33.369078;

	m_PosArray[3][4].x = 125.019361;
	m_PosArray[3][4].y = 33.482301;


	m_PosArray[4][0].x = 124.985978;
	m_PosArray[4][0].y = 34.178939;

	m_PosArray[4][1].x = 125.221714;
	m_PosArray[4][1].y = 34.154335;

	m_PosArray[4][2].x = 125.349871;
	m_PosArray[4][2].y = 34.025333;

	m_PosArray[4][3].x = 125.156281;
	m_PosArray[4][3].y = 33.889582;

	m_PosArray[4][4].x = 124.524693;
	m_PosArray[4][4].y = 34.082919;

	m_PosArray[5][0].x = 125.615033;
	m_PosArray[5][0].y = 35.141936;

	m_PosArray[5][1].x = 125.304281;
	m_PosArray[5][1].y = 35.152315;

	m_PosArray[5][2].x = 125.416250;
	m_PosArray[5][2].y = 35.324816;

	m_PosArray[5][3].x = 125.556881;
	m_PosArray[5][3].y = 35.461861;

	m_PosArray[5][4].x = 125.277377;
	m_PosArray[5][4].y = 35.482205;

	m_PosArray[6][0].x = 129.439246;
	m_PosArray[6][0].y = 35.065031;

	m_PosArray[6][1].x = 129.638385;
	m_PosArray[6][1].y = 35.069473;

	m_PosArray[6][2].x = 129.829956;
	m_PosArray[6][2].y = 35.144220;

	m_PosArray[6][3].x = 129.971343;
	m_PosArray[6][3].y = 35.300135;

	m_PosArray[6][4].x = 130.185248;
	m_PosArray[6][4].y = 35.264478;


	m_PosArray[7][0].x = 129.711755;
	m_PosArray[7][0].y = 36.056304;

	m_PosArray[7][1].x = 129.701184;
	m_PosArray[7][1].y = 35.899888;

	m_PosArray[7][2].x = 129.794328;
	m_PosArray[7][2].y = 35.747631;

	m_PosArray[7][3].x = 129.992369;
	m_PosArray[7][3].y = 35.659137;

	m_PosArray[7][4].x = 129.930729;
	m_PosArray[7][4].y = 35,928343;


	m_PosArray[8][0].x = 130.456828;
	m_PosArray[8][0].y = 35.973696;

	m_PosArray[8][1].x = 130.672191;
	m_PosArray[8][1].y = 36.035007;

	m_PosArray[8][2].x = 130.673264;
	m_PosArray[8][2].y = 36.216553;

	m_PosArray[8][3].x = 130.504130;
	m_PosArray[8][3].y = 36.311369;

	m_PosArray[8][4].x = 130.322750;
	m_PosArray[8][4].y = 36.198051;


	m_PosArray[9][0].x = 129.713513;
	m_PosArray[9][0].y = 36.521028;

	m_PosArray[9][1].x = 129.683527;
	m_PosArray[9][1].y = 36.650551;

	m_PosArray[9][2].x = 129.796903;
	m_PosArray[9][2].y = 36.802435;

	m_PosArray[9][3].x = 129.946212;
	m_PosArray[9][3].y = 36.931807;

	m_PosArray[9][4].x = 130.166277;
	m_PosArray[9][4].y = 37.032518;

	m_PosArray[10][0].x = 128.247023;
	m_PosArray[10][0].y = 34.277622;

	m_PosArray[10][1].x = 128.579634;
	m_PosArray[10][1].y = 34.399573;

	m_PosArray[10][2].x = 128.216242;
	m_PosArray[10][2].y = 34.013136;

	m_PosArray[10][3].x = 128.458006;
	m_PosArray[10][3].y = 33.732434;

	m_PosArray[10][4].x = 128.879803;
	m_PosArray[10][4].y = 34.202720;

	m_PosArray[11][0].x = 127.066284;
	m_PosArray[11][0].y = 33.260531;

	m_PosArray[11][1].x = 127.037002;
	m_PosArray[11][1].y = 33.142912;

	m_PosArray[11][2].x = 126.818562;
	m_PosArray[11][2].y = 33.119091;

	m_PosArray[11][3].x = 126.781471;
	m_PosArray[11][3].y = 32.959398;

	m_PosArray[11][4].x = 126.543668;
	m_PosArray[11][4].y = 32.995400;

	m_PosArray[12][0].x = 125.907317;
	m_PosArray[12][0].y = 35.790683;

	m_PosArray[12][1].x = 125.784817;
	m_PosArray[12][1].y = 35.955912;

	m_PosArray[12][2].x = 125.702191;
	m_PosArray[12][2].y = 35.774711;

	m_PosArray[12][3].x = 125.580199;
	m_PosArray[12][3].y = 35.942917;

	m_PosArray[12][4].x = 125.499657;
	m_PosArray[12][4].y = 35.797831;

	m_PosArray[13][0].x = 126.138167;
	m_PosArray[13][0].y = 36.410122;

	m_PosArray[13][1].x = 126.013218;
	m_PosArray[13][1].y = 36.333152;

	m_PosArray[13][2].x = 125.822506;
	m_PosArray[13][2].y = 36.344460;

	m_PosArray[13][3].x = 125.712147;
	m_PosArray[13][3].y = 36.497201;

	m_PosArray[13][4].x = 125.431072;
	m_PosArray[13][4].y = 36.557159;

	m_PosArray[14][0].x = 126.1476479;
	m_PosArray[14][0].y = 37.429315;

	m_PosArray[14][1].x = 126.151652;
	m_PosArray[14][1].y = 37.301736;

	m_PosArray[14][2].x = 125.882697;
	m_PosArray[14][2].y = 37.326726;

	m_PosArray[14][3].x = 125.757674;
	m_PosArray[14][3].y = 37.179409;

	m_PosArray[14][4].x = 125.642919;
	m_PosArray[14][4].y = 37.306157;

	m_PosArray[15][0].x = 124.334796;
	m_PosArray[15][0].y = 37.132162;

	m_PosArray[15][1].x = 124.561178;
	m_PosArray[15][1].y = 36.991508;

	m_PosArray[15][2].x = 124.651546;
	m_PosArray[15][2].y = 36.813719;

	m_PosArray[15][3].x = 124.423731;
	m_PosArray[15][3].y = 36.722389;

	m_PosArray[15][4].x = 124.195920;
	m_PosArray[15][4].y = 36.823066;

	m_PosArray[16][0].x = 128.878586;
	m_PosArray[16][0].y = 38.224916;

	m_PosArray[16][1].x = 128.918469;
	m_PosArray[16][1].y = 38.109319;

	m_PosArray[16][2].x = 128.997279;
	m_PosArray[16][2].y = 38.022845;

	m_PosArray[16][3].x = 129.168289;
	m_PosArray[16][3].y = 38.102402;

	m_PosArray[16][4].x = 129.130862;
	m_PosArray[16][4].y = 38.224435;

	m_PosArray[17][0].x = 130.057977;
	m_PosArray[17][0].y = 38.089042;

	m_PosArray[17][1].x = 130.238302;
	m_PosArray[17][1].y = 38.189451;

	m_PosArray[17][2].x = 129.996315;
	m_PosArray[17][2].y = 38.384777;

	m_PosArray[17][3].x = 129.721189;
	m_PosArray[17][3].y = 38.372009;

	m_PosArray[17][4].x = 129.817862;
	m_PosArray[17][4].y = 38.213638;

	m_PosArray[18][0].x = 131.568806;
	m_PosArray[18][0].y = 37.020158;

	m_PosArray[18][1].x = 131.286870;
	m_PosArray[18][1].y = 36.941958;

	m_PosArray[18][2].x = 131.105382;
	m_PosArray[18][2].y = 37.040439;

	m_PosArray[18][3].x = 130.946562;
	m_PosArray[18][3].y = 37.119958;

	m_PosArray[18][4].x = 130.900443;
	m_PosArray[18][4].y = 36.988062;

	m_PosArray[19][0].x = 125.136306;
	m_PosArray[19][0].y = 36.279044;


	m_PosArray[19][1].x = 124.931933;
	m_PosArray[19][1].y = 36.162277;

	m_PosArray[19][2].x = 124.612169;
	m_PosArray[19][2].y = 36.274389;

	m_PosArray[19][3].x = 124.572249;
	m_PosArray[19][3].y = 36.054090;

	m_PosArray[19][4].x = 124.374028;
	m_PosArray[19][4].y = 36.245618;

	for(int i= 0; i < maxidx; ++i){
		m_Pos[i] = m_PosArray[i][0];
		m_Start[i] = m_PosArray[i][0];
		m_End[i] = m_PosArray[i][1];
		m_flag[i] = false;
	}
}

double Ownshipstep = 0.001;
void GetNextXY(int idx)
{
	if(m_Pos[idx].x != m_End[idx].x){
		if(m_Start[idx].x < m_End[idx].x)
		{
			m_Pos[idx].x += Ownshipstep;
		}else if(m_Start[idx].x > m_End[idx].x){
			m_Pos[idx].x -= Ownshipstep;
		}
	}

	if(m_Pos[idx].y != m_End[idx].y){
		if(m_Start[idx].y < m_End[idx].y)
		{
			m_Pos[idx].y += Ownshipstep;
		}else if(m_Start[idx].y > m_End[idx].y){
			m_Pos[idx].y -= Ownshipstep;
		}
	}

	if(m_Pos[idx].x > m_End[idx].x)
		m_Pos[idx].x = m_End[idx].x;

	if(m_Pos[idx].y > m_End[idx].y)
		m_Pos[idx].y = m_End[idx].y;

	if(m_Pos[idx].x == m_End[idx].x && m_Pos[idx].y == m_End[idx].y){
		m_Start[idx] = m_PosArray[idx][m_idx[idx]];
		if(m_flag[idx] && m_idx[idx] == 0){
			m_flag[idx] = false;
		}
		if(m_idx[idx] > 1){
			m_flag[idx] = true;
		}
		if(m_flag[idx])
			m_idx[idx] -= 1;
		else
			m_idx[idx] += 1;
		m_End[idx] = m_PosArray[idx][m_idx[idx]];
	}
}

LocationMgr::LocationMgr()
{
	InitOwnshipXY();
}
LocationMgr::~LocationMgr()
{
}

POS& LocationMgr::GetLocation(int n)
{
	GetNextXY(n);
	return m_Pos[n];

}