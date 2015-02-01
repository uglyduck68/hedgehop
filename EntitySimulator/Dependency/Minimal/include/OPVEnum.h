#pragma once
namespace OPV
{
	/*! @enum	_ENUM_SIMULATOR_ID
	 *	@brief	시뮬레이터 아이디
	 */
	 enum _ENUM_SIMULATOR_ID {
		DCOY = 1,
		EOTS,
		ESM,
		GUN,
		LINK,
		NVR,
		OSS,
		SSM,
		SVR
	 };

	/*!	@enum	_ENUM_SIMULATOR_MGR_COMMAND
	 *	@brief	시뮬레이터 명령
	 */
	enum _ENUM_SIMULATOR_MGR_COMMAND {
		Restart,
		Kill,
		Windows_Off,
		Connect_MMI
	};
	
	/*! @enum	_ENUM_SIMULATION_MGR_COMMAND
	 *	@brief	시뮬레이션 명령
	 */
	 enum _ENUM_SIMULATION_MGR_COMMAND {
	 	Start,
	 	Pause,
		Resume,
	 	Stop
	 };
	/*! @enum	_ENUM_LINK_CONNECTION_COMMAND
	 *	@brief	링크 연동 상태
	 */
	 enum _ENUM_LINK_CONNECTION_COMMAND {
		Connect,
	 	Disconnect
	 };

	/*! @enum	_ENUM_PARAMETER_DISTRIBUTION_COMMAND
	 *	@brief	파라미터 연동 관리
	 */	 
	 enum _ENUM_PARAMETER_DISTRIBUTION_COMMAND {
	 	Start_,
		End_
	};
	 /*! @enum	_ENUM_SIMULATION_WEATHER
	 *	@brief	시뮬레이션 날씨
	 */
	 enum _ENUM_SIMULATION_WEATHER {
	 	SUNNY = 1,
	 	RAINY,
		STORMY,
	 	CLOUDY,
		FOGGY,
		SNOW,
		BLIZZARD,
		MIST
	 };
	 
	 /*! @enum	_ENUM_ENTITY_TYPE
	 *	@brief	엔티티 타입
	 */
	 enum _ENUM_ENTITY_TYPE {
	 	AW = 1, /// Aircraft Warfare
	 	SuW, /// Surface Warfare
		SW, /// Submarine Warare
	 };

	 /*! @enum	_ENUM_ENTITY_CLASS
	 *	@brief	엔티티 클래스
	 */
	 enum _ENUM_ENTITY_CLASS {
	 	Unknown = 1,
	 	FixedWing_Attack,
		RotaryWing,
		FixedWing_Bomber,
		Combatant_AssultVessel,
		Combatant_Frigate,
		Combatant_Destroyer,
		Patrol,
		Cruiser,
		Submarine,
		Missile,
		Torpedo,
		Decoy
	 };
	 /*! @enum	_ENUM_MISSILE_TYPE
	 *	@brief	미사일 타입
	 */
	 enum _ENUM_MISSILE_TYPE {
		 Stub
	};
	 /*! @enum	_ENUM_MISSILE_CATEGORY
	 *	@brief	미사일 종류
	 */
	 enum _ENUM_MISSILE_CATEGORY {
		/// Stub
	};	 
	 /*! @enum	_ENUM_AMMUNITION_TYPE
	 *	@brief	포탄 타입
	 */
	 enum _ENUM_AMMUNITION_TYPE {
		/// Stub
	};
	 /*! @enum	_ENUM_AMMUNITION_CATEGORY
	 *	@brief	포탄 종류
	 */
	 enum _ENUM_AMMUNITION_CATEGORY {
		/// Stub
	};
};