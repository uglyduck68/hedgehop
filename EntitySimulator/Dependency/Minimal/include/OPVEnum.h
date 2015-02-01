#pragma once
namespace OPV
{
	/*! @enum	_ENUM_SIMULATOR_ID
	 *	@brief	�ùķ����� ���̵�
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
	 *	@brief	�ùķ����� ���
	 */
	enum _ENUM_SIMULATOR_MGR_COMMAND {
		Restart,
		Kill,
		Windows_Off,
		Connect_MMI
	};
	
	/*! @enum	_ENUM_SIMULATION_MGR_COMMAND
	 *	@brief	�ùķ��̼� ���
	 */
	 enum _ENUM_SIMULATION_MGR_COMMAND {
	 	Start,
	 	Pause,
		Resume,
	 	Stop
	 };
	/*! @enum	_ENUM_LINK_CONNECTION_COMMAND
	 *	@brief	��ũ ���� ����
	 */
	 enum _ENUM_LINK_CONNECTION_COMMAND {
		Connect,
	 	Disconnect
	 };

	/*! @enum	_ENUM_PARAMETER_DISTRIBUTION_COMMAND
	 *	@brief	�Ķ���� ���� ����
	 */	 
	 enum _ENUM_PARAMETER_DISTRIBUTION_COMMAND {
	 	Start_,
		End_
	};
	 /*! @enum	_ENUM_SIMULATION_WEATHER
	 *	@brief	�ùķ��̼� ����
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
	 *	@brief	��ƼƼ Ÿ��
	 */
	 enum _ENUM_ENTITY_TYPE {
	 	AW = 1, /// Aircraft Warfare
	 	SuW, /// Surface Warfare
		SW, /// Submarine Warare
	 };

	 /*! @enum	_ENUM_ENTITY_CLASS
	 *	@brief	��ƼƼ Ŭ����
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
	 *	@brief	�̻��� Ÿ��
	 */
	 enum _ENUM_MISSILE_TYPE {
		 Stub
	};
	 /*! @enum	_ENUM_MISSILE_CATEGORY
	 *	@brief	�̻��� ����
	 */
	 enum _ENUM_MISSILE_CATEGORY {
		/// Stub
	};	 
	 /*! @enum	_ENUM_AMMUNITION_TYPE
	 *	@brief	��ź Ÿ��
	 */
	 enum _ENUM_AMMUNITION_TYPE {
		/// Stub
	};
	 /*! @enum	_ENUM_AMMUNITION_CATEGORY
	 *	@brief	��ź ����
	 */
	 enum _ENUM_AMMUNITION_CATEGORY {
		/// Stub
	};
};