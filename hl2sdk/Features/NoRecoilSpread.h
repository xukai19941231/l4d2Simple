#pragma once
#include "BaseFeatures.h"

class CViewManager : public CBaseFeatures
{
public:
	CViewManager();
	~CViewManager();

	void OnCreateMove(CUserCmd* cmd, bool* bSendPacket) override;
	virtual void OnFrameStageNotify(ClientFrameStage_t stage) override;
	virtual void OnMenuDrawing() override;
	virtual void OnEnginePaint(PaintMode_t mode);

	bool ApplySilentAngles(const QAngle& viewAngles);

	bool StartSilent(CUserCmd* cmd);
	bool FinishSilent(CUserCmd* cmd);

	void RemoveSpread(CUserCmd* cmd);
	void RemoveRecoil(CUserCmd* cmd);

	void RunRapidFire(CUserCmd* cmd, CBasePlayer* local, CBaseWeapon* weapon);

private:
	bool m_bNoSpread = false;
	bool m_bNoRecoil = false;
	bool m_bNoVisRecoil = false;
	bool m_bRapidFire = false;

	bool m_bRecoilCrosshair = false;
	bool m_bSpreadCrosshair = false;

private:
	bool m_bHasApplySilent = false;
	QAngle m_vecSilentAngles;

private:
	QAngle m_vecAngles;
	float m_fSideMove = 0.0f;
	float m_fForwardMove = 0.0f;
	float m_fUpMove = 0.0f;

private:
	Vector m_vecPunch;
	Vector m_vecSpread;

private:
	bool m_bRapidIgnore = true;
};

extern CViewManager* g_pViewManager;