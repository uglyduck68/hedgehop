#include "StdAfx.h"
#include "..\include\OceanTest.h"


OceanTest::OceanTest(void) :
	m_fWaveAmp(0.0f),
	m_fWaveFreq(0.0f)
{
}


OceanTest::~OceanTest(void)
{
}

void OceanTest::createScene(void)
{
   // Define a plane mesh that will be used for the ocean surface
	//m_pPlane	= new /*(nothrow)*/ Ogre::MovablePlane("OceanPlane");
	//m_pPlane->d	= 0;
	//m_pPlane->normal	= Ogre::Vector3::UNIT_Y;

//    Ogre::Plane oceanPlane;

    m_Plane.normal	= Ogre::Vector3::UNIT_Y;
    m_Plane.d		= GetSurface();

    Ogre::MeshManager::getSingleton().createPlane("OceanPlane",
        Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        m_Plane,
        MAX_WIDTH, MAX_HEIGHT, XSEGMENT, YSEGMENT, true, 1, 1, 1, Ogre::Vector3::UNIT_Z);

    m_pOceanEnt = mSceneMgr->createEntity( "OceanTest", "OceanPlane" );

	if( m_pOceanEnt )
	{
		m_pOcean	= mSceneMgr->getRootSceneNode()->createChildSceneNode("Ocean"/*, Ogre::Vector3(0, GetSurface(), 0)*/);
		m_pOcean->attachObject(m_pOceanEnt);
//		m_pOcean->translate(0, 1000, 0);

		// axis is "axis.png" in "./resource" folder.
		m_pOceanEnt->setMaterialName("Ocean2_Cg");		// "OceanCg" -> "Ocean2_Cg" -> "OceanTest_Cg"
		m_pOceanEnt->setCastShadows(false);
//		m_pOceanEnt->setQueryFlags(1);	// if QueryFlag is 0xffffffff then this is useless

	}
	else
	{
		DebugPrintf("Error: fail to create ocean entity\n");
	}

	///////////////////////////////////////////////////////////////////////////
	// load Ocean.control file to control ocean wave Fx
	//////////////////////////////////////////////////////////////////////////////
	loadAllMaterialControlFiles(mMaterialControlsContainer);

	// 0 means "Ocean2_Cg"
	mCurrentMaterial	= 0;

	mActiveMaterial = Ogre::MaterialManager::getSingleton().getByName( "Ocean2_Cg" /*mMaterialControlsContainer[mCurrentMaterial].getMaterialName()*/ );
	mActiveMaterial->load();

}

int OceanTest::ChangeFragmentVertexValue(int nIndex, Real& TargetValue, Real Value)
{
	//////////////////////////////////////////////////////////////////////////////
	// HERE control wave Fx
	///////////////////////////////////////////////////////////////////////////

	// The index of waveFreq is 5 from Ocean.control file.
    const ShaderControl& ActiveShaderDef = mMaterialControlsContainer[mCurrentMaterial].getShaderControl( nIndex );

	float val = TargetValue + Value;

	if( val > ActiveShaderDef.MaxVal )
		val	= ActiveShaderDef.MaxVal;

	else if( val < ActiveShaderDef.MinVal )
		val	= ActiveShaderDef.MinVal;

	TargetValue		= val;

	Ogre::Technique* currentTechnique = mActiveMaterial->getSupportedTechnique(0);
	
	if(currentTechnique)
	{
		mActivePass = currentTechnique->getPass(0);
		if(mActivePass)
		{
            if (mActivePass->hasFragmentProgram())
            {
				mActiveFragmentProgram = mActivePass->getFragmentProgram();
    			mActiveFragmentParameters = mActivePass->getFragmentProgramParameters();
            }
            if (mActivePass->hasVertexProgram())
            {
				mActiveVertexProgram = mActivePass->getVertexProgram();
				mActiveVertexParameters = mActivePass->getVertexProgramParameters();
            }
		}
	}

	// use param name to get index : use appropriate parameters ptr
	const Ogre::GpuConstantDefinition& def = 
		mActiveVertexParameters->getConstantDefinition(ActiveShaderDef.ParamName);

	ActiveShaderDef.PhysicalIndex = def.physicalIndex;

	// use index to get RealConstantEntry
	const float* pFloat = mActiveVertexParameters->getFloatPointer(ActiveShaderDef.PhysicalIndex);

	if(mActivePass)
	{
		switch(ActiveShaderDef.ValType)
		{
			case GPU_VERTEX:
			case GPU_FRAGMENT:
				{
					GpuProgramParametersSharedPtr activeParameters =
						(ActiveShaderDef.ValType == GPU_VERTEX) ?
							mActiveVertexParameters : mActiveFragmentParameters;

					if(!activeParameters.isNull())
					{
						activeParameters->_writeRawConstant(
							ActiveShaderDef.PhysicalIndex + ActiveShaderDef.ElementIndex, val);
					}
				}
				break;
			default:
				break;
		}
	}

	return 0;
}


bool OceanTest::keyPressed(const OIS::KeyEvent &arg)
{

	if( arg.key == OIS::KC_1 )
		ChangeFragmentVertexValue( 5, m_fWaveFreq, 0.01 );
	else if( arg.key == OIS::KC_2 )
		ChangeFragmentVertexValue( 5, m_fWaveFreq, -0.01 );
	else if( arg.key == OIS::KC_3 )
		ChangeFragmentVertexValue( 6, m_fWaveAmp, 1 );
	else if( arg.key == OIS::KC_4 )
		ChangeFragmentVertexValue( 6, m_fWaveAmp, -1 );
	return BaseApplication::keyPressed( arg );
}

bool OceanTest::keyReleased(const OIS::KeyEvent &arg)
{
	return BaseApplication::keyReleased( arg );
}

