#ifndef RM_OPV_INCLUDE_RM_2525C_SYMBOL_TYPES_H_
#define RM_OPV_INCLUDE_RM_2525C_SYMBOL_TYPES_H_

#include "rmCommon.h"

namespace rmOPV {

//--------------------------------------------------------------------------
struct RM_SYMBOL_CLASSIFIER
{
	function<
		tuple<RM_INT, RM_SYMBOL_CLASSIFIER>(const RM_INT&)> Classify;
	RM_SYMBOL_CLASSIFIER(function<
		tuple<RM_INT, RM_SYMBOL_CLASSIFIER>(const RM_INT&)> func)
		: Classify(func) { }
};

extern RM_SYMBOL_CLASSIFIER rmNoStatementClassClassifier;
extern RM_SYMBOL_CLASSIFIER rmNoStatementKindClassifier;

#define RM_SYMBOL_NO_STATEMENT ('_')

//--------------------------------------------------------------------------
// identity
//--------------------------------------------------------------------------
enum RM_SYMBOL_IDENTITY // reference Enum.cs
{
	IDENTITY_Pending,
	IDENTITY_Unknown,
	IDENTITY_Assume_Friend,
	IDENTITY_Friend,
	IDENTITY_Hostile,
	IDENTITY_Neutral,
	IDENTITY_Suspect
};

//--------------------------------------------------------------------------
// category
//--------------------------------------------------------------------------
enum RM_SYMBOL_CATEGORY
{
	CATEGORY_Surface,
	CATEGORY_Air,	
	CATEGORY_SubSurface,
	CATEGORY_Ground,
	CATEGORY_No_Statement
};

extern RM_SYMBOL_CLASSIFIER rmCategoryClassifier;

//--------------------------------------------------------------------------
// Air Class
//--------------------------------------------------------------------------
enum RM_SYMBOL_CLASS_AIR
{
	CLASS_AIR_No_Statement,
	CLASS_AIR_Fighter,
	CLASS_AIR_HELO,        // Helicopter
	CLASS_AIR_Missile,
	CLASS_AIR_NON_MIL,     // Non Military
	CLASS_AIR_RPV,         // Remote Pilotless Vehicle
	CLASS_AIR_TRANSPT      // Transport
};

extern RM_SYMBOL_CLASSIFIER rmAirClassClassifier;

//--------------------------------------------------------------------------
enum RM_SYMBOL_KIND_AIR_FIGHTER
{
	KIND_AIR_FIGHTER_F_l5_Eagle,
	KIND_AIR_FIGHTER_F_l6_Falcon,
	KIND_AIR_FIGHTER_MIG_l9, 
	KIND_AIR_FIGHTER_MIG_21_Fishbed, 
	KIND_AIR_FIGHTER_F_117_Stealth
};

enum RM_SYMBOL_KIND_AIR_HELO
{
	KIND_AIR_HELO_HAS_MK3_Lynx,
	KIND_AIR_HELO_UH_l_Utility
};

enum RM_SYMBOL_KIND_AIR_TRANSPT
{
	KIND_AIR_TRANSPT_AN_22,
	KIND_AIR_TRANSPT_C_130_Hercules
};

//--------------------------------------------------------------------------
enum RM_SYMBOL_MISSION_AIR_FIGHTER
{
	MISSION_AIR_FIGHTER_Strike
};

enum RM_SYMBOL_MISSION_AIR_HELO
{
	MISSION_AIR_HELO_ASW, // Anti Submarine Warfare
	MISSION_AIR_HELO_CAP  // Combat Air Support
};

enum RM_SYMBOL_MISSION_AIR_RPV
{
	MISSION_AIR_RPV_SAR, // Search & Rescue
	MISSION_AIR_RPV_SPECIAL // Special Mission
};

enum RM_SYMBOL_MISSION_AIR_TRANSPT
{
	MISSION_AIR_TRNASPT_CAP // Combat Air Support
};


//--------------------------------------------------------------------------
// surface class
//--------------------------------------------------------------------------
enum RM_SYMBOL_CLASS_SURFACE
{
	CLASS_SURFACE_No_Statement,
	CLASS_SURFACE_A_C_Carrier,
	CLASS_SURFACE_ACV, // Air Cushion Vehicle
	CLASS_SURFACE_AMPHIB, // AmPhibious
	CLASS_SURFACE_Battleship,
	CLASS_SURFACE_CORVET,
	CLASS_SURFACE_Cruiser,
	CLASS_SURFACE_DD,
	CLASS_SURFACE_FAST_PB,
	CLASS_SURFACE_SD, // Line
	CLASS_SURFACE_FISHING,
	CLASS_SURFACE_Frigate,
	CLASS_SURFACE_Landing_Craft,
	CLASS_SURFACE_MERCHNT,
	CLASS_SURFACE_MINE_SW,
	CLASS_SURFACE_NON_MIL, // Non-Military
	CLASS_SURFACE_TRANSPT, // Transport
};


//--------------------------------------------------------------------------
enum RM_SYMBOL_KIND_SURFACE_A_C_CARRIER
{
	KIND_SURFACE_A_C_CARRIER_CV, 
	KIND_SURFACE_A_C_CARRIER_A,
	KIND_SURFACE_A_C_CARRIER_N
};

enum RM_SYMBOL_KIND_SURFACE_ACV
{
	KIND_SURFACE_ACV_HOVER // Hovercraft
};

enum RM_SYMBOL_KIND_SURFACE_AMPHIB
{
	KIND_SURFACE_AMPHIB_LPD, // Landing Amphibious Dock
	KIND_SURFACE_AMPHIB_LPH  // Assault Ship (Helo)
};

enum RM_SYMBOL_KIND_SURFACE_BATTLESHIP
{
	KIND_SURFACE_BATTLESHIP_BB // Battleship
};

enum RM_SYMBOL_KIND_SURFACE_CORVET
{
	KIND_SURFACE_CORVET_CORVET, // Missile Corvette
	KIND_SURFACE_CORVET_PCC // Patrol Combat Corvette
};

enum RM_SYMBOL_KIND_SURFACE_CRUISER
{
	KIND_SURFACE_CRUISER_CG,
	KIND_SURFACE_CRUISER_CGN // Cruiser/Nuclear Powered
};

enum RM_SYMBOL_KIND_SURFACE_DD
{
	KIND_SURFACE_DD_DD, 
	KIND_SURFACE_DD_G,
	KIND_SURFACE_DD_H
};

enum RM_SYMBOL_KIND_SURFACE_FAST_PB
{
	KIND_SURFACE_FAST_PB_PB, // Patrol Boat
	KIND_SURFACE_FAST_PB_PG, // Patrol Gun Boat/Fast Attack Craft, Gun
	KIND_SURFACE_FAST_PB_PGM // Patrol Gun Missile
};

enum RM_SYMBOL_KIND_SURFACE_FRIGATE
{
	KIND_SURFACE_FRIGATE_FF,
	KIND_SURFACE_FRIGATE_G,
	KIND_SURFACE_FRIGATE_H
};

enum RM_SYMBOL_KIND_SURFACE_LANDING_CRAFT
{
	KIND_SURFACE_LANDING_CRAFT_LCM, // Landing Craft -  Medium
	KIND_SURFACE_LANDING_CRAFT_LCU_Utility, // Landing Craft - Utility
	KIND_SURFACE_LANDING_CRAFT_LCU_Vehicles, // Landing Craft - Vehicles
	KIND_SURFACE_LANDING_CRAFT_LCU_Personnel  // Landing Craft - Personnel
};

enum RM_SYMBOL_KIND_SURFACE_MINE_SW
{ // Mine COunter Measures
	KIND_SURFACE_MINE_SW_MCM,
	KIND_SURFACE_MINE_SW_MHC,
	KIND_SURFACE_MINE_SW_MSC,
	KIND_SURFACE_MINE_SW_MSF,
	KIND_SURFACE_MINE_SW_MSO
};

enum RM_SYMBOL_KIND_SURFACE_NON_MIL
{
	KIND_SURFACE_NON_MIL_MP, // Maritime Police Vessel
	KIND_SURFACE_NON_MIL_HOVER // Hovercraft
};

enum RM_SYMBOL_KIND_SURFACE_TRANSPT
{
	KIND_SURFACE_TRANSPT_AK, // Cargo
	KIND_SURFACE_TRANSPT_TA  // TransPort/Aux
};

//--------------------------------------------------------------------------
enum RM_SYMBOL_MISSION_SURFACE_A_C_CARRIER
{
	MISSION_SURFACE_A_C_CARRIER_ASSIST, // Assisting Ship
	MISSION_SURFACE_A_C_CARRIER_SUPPORT // Supporting ship
};

enum RM_SYMBOL_MISSION_SURFACE_ACV
{
	MISSION_SURFACE_ACV_ASSIST, // Assisting Ship
	MISSION_SURFACE_ACV_SUPPORT // Supporting ship
};

enum RM_SYMBOL_MISSION_SURFACE_AMPHIB
{
	MISSION_SURFACE_AMPHIB_ASSIST, // Assisting Ship
	MISSION_SURFACE_AMPHIB_SUPPORT, // Supporting ship
	MISSION_SURFACE_AMPHIB_NGFS // Naval Gunfire Support
};

enum RM_SYMBOL_MISSION_SURFACE_BATTLESHIP
{
	MISSION_SURFACE_BATTLESHIP_AAW,
	MISSION_SURFACE_BATTLESHIP_ASW,
	MISSION_SURFACE_BATTLESHIP_SUW,
	MISSION_SURFACE_BATTLESHIP_ATTACK, // Attacking Ship,
	MISSION_SURFACE_BATTLESHIP_CMP_WAR, // ComPosite Warfare
	MISSION_SURFACE_BATTLESHIP_NGFS, // Naval Gunfire Support
	MISSION_SURFACE_BATTLESHIP_Strike
};

enum RM_SYMBOL_MISSION_SURFACE_CORVET
{
	MISSION_SURFACE_CORVET_AAW,
	MISSION_SURFACE_CORVET_ASW,
	MISSION_SURFACE_CORVET_SUW,
	MISSION_SURFACE_CORVET_ATTACK, // Attacking Ship,
	MISSION_SURFACE_CORVET_ASSIST, // Assisting Ship
	MISSION_SURFACE_CORVET_Patrol,
	MISSION_SURFACE_CORVET_Picket,
	MISSION_SURFACE_CORVET_Strike
};

enum RM_SYMBOL_MISSION_SURFACE_CRUISER
{
	MISSION_SURFACE_CRUISER_SPECIAL // Special mission
};

enum RM_SYMBOL_MISSION_SURFACE_DD
{
	MISSION_SURFACE_DD_AAW,
	MISSION_SURFACE_DD_ASW,
	MISSION_SURFACE_DD_SUW,
	MISSION_SURFACE_DD_ATTACK, // Attacking Ship,
	MISSION_SURFACE_DD_CMP_WAR, // ComPosite Warfare
	MISSION_SURFACE_DD_NGFS, // Naval Gunfire Support
	MISSION_SURFACE_DD_Strike
};

enum RM_SYMBOL_MISSION_SURFACE_FAST_PB
{
	MISSION_SURFACE_FAST_PB_AAW,
	MISSION_SURFACE_FAST_PB_ASW,
	MISSION_SURFACE_FAST_PB_SUW,
	MISSION_SURFACE_FAST_PB_ATTACK, // Attacking Ship,
	MISSION_SURFACE_FAST_PB_CMP_WAR, // ComPosite Warfare
	MISSION_SURFACE_FAST_PB_NGFS, // Naval Gunfire Support
	MISSION_SURFACE_FAST_PB_Patrol,
	MISSION_SURFACE_FAST_PB_Picket,
	MISSION_SURFACE_FAST_PB_SAR, // Search & Rescue
	MISSION_SURFACE_FAST_PB_Strike
};

enum RM_SYMBOL_MISSION_SURFACE_FRIGATE
{
	MISSION_SURFACE_FRIGATE_AAW,
	MISSION_SURFACE_FRIGATE_ASW,
	MISSION_SURFACE_FRIGATE_SUW, 
	MISSION_SURFACE_FRIGATE_ATTACK, // Attacking Ship,
	MISSION_SURFACE_FRIGATE_CMP_WAR, // ComPosite Warfare
	MISSION_SURFACE_FRIGATE_NGFS, //Naval Gunfire Support
	MISSION_SURFACE_FRIGATE_SAR, // Search & Rescue
	MISSION_SURFACE_FRIGATE_Strike
};

enum RM_SYMBOL_MISSION_SURFACE_LANDING_CRAFT
{
	MISSION_SURFACE_LANDING_CRAFT_ASSIST, // Assisting Ship
	MISSION_SURFACE_LANDING_CRAFT_NGFS, // Naval Gunfire Support
	MISSION_SURFACE_LANDING_CRAFT_SUPPORT // Supporting ship
};

enum RM_SYMBOL_MISSION_SURFACE_MINE_SW
{ 
	MISSION_SURFACE_MINE_SW_SAU // Search Attack Unit
};

enum RM_SYMBOL_MISSION_SURFACE_NON_MIL
{
	MISSION_SURFACE_NON_MIL_Patrol
};

enum RM_SYMBOL_MISSION_SURFACE_TRANSPT
{
	MISSION_SURFACE_TRANSPT_ASSIST, // Assisting Ship
	MISSION_SURFACE_TRANSPT_LOGIST, // Logistics,
	MISSION_SURFACE_TRANSPT_REPLEN, // Replenishment,
	MISSION_SURFACE_TRANSPT_SUPPORT // Supporting ship 
};


//--------------------------------------------------------------------------
// sub surface class
//--------------------------------------------------------------------------
enum RM_SYMBOL_CLASS_SUBSURFACE
{
	CLASS_SUBSURFACE_No_Statement,
	CLASS_SUBSURFACE_NON_SUB, // Non-Submarine
	CLASS_SUBSURFACE_Probable_Submarine, 
	CLASS_SUBSURFACE_Certain_Submarine
};

//--------------------------------------------------------------------------
enum RM_SYMBOL_KIND_SUB_SURFACE_NON_SUB
{
	KIND_SUB_SURFACE_NON_SUB_torpede,
	KIND_SUB_SURFACE_NON_SUB_decoy,
	KIND_SUB_SURFACE_NON_SUB_mine
};

enum RM_SYMBOL_KIND_SUB_SURFACE_PROBABLE_SUBMARINE
{
	KIND_SUB_SURFACE_PROBABLE_SUBMARINE_PRO_UNK_SUB // Propulsion Unknown Sub
};

enum RM_SYMBOL_KIND_SUB_SURFACE_CERTAIN_SUBMARINE
{
	KIND_SUB_SURFACE_CERTAIN_SUBMARINE_NU_SUB, // Nuclear Submarine
	KIND_SUB_SURFACE_CERTAIN_SUBMARINE_DE_SUB  // Diesel Submarine
};

//--------------------------------------------------------------------------
enum RM_SYMBOL_MISSION_SUB_SURFACE_NON_SUB
{
	MISSION_SUB_SURFACE_NON_SUB_ANTISHP, // Anti Shipping
	MISSION_SUB_SURFACE_NON_SUB_ANTISUB  // Anti Submarine
};

enum RM_SYMBOL_MISSION_SUB_SURFACE_PROBABLE_SUBMARINE
{
	MISSION_SUB_SURFACE_PROBABLE_SUBMARINE_ANTISHP, // Anti Shipping
	MISSION_SUB_SURFACE_PROBABLE_SUBMARINEANTISUB, // Anti Submarine
	MISSION_SUB_SURFACE_PROBABLE_SUBMARINEPatrol
};

enum RM_SYMBOL_MISSION_SUB_SURFACE_CERTAIN_SUBMARINE
{
	MISSION_SUB_SURFACE_CERTAIN_SUBMARINE_ANTISHP, // Anti Shipping
	MISSION_SUB_SURFACE_CERTAIN_SUBMARINE_ANTISUB, // Anti Submarine
	MISSION_SUB_SURFACE_CERTAIN_SUBMARINE_Patrol
};

//--------------------------------------------------------------------------
// special point
//--------------------------------------------------------------------------
enum RM_SYMBOL_CLASS_SPECIAL_POINT
{
	CLASS_SPECIAL_POINT_No_Statement,
	CLASS_SPECIAL_POINT_Reference_Point
};


//--------------------------------------------------------------------------


}

#endif // RM_OPV_INCLUDE_RM_2525C_SYMBOL_TYPES_H_