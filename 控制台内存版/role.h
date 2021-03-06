#pragma once

namespace role {
	int getRoleLevel();
	std::wstring getRoleJobName();
	int getCurrentRoleFatigueValue();
	ROLE_POS getRolePos();
	int getRoleStatus();
	void releaseSkillByKey(int keyCode, int s);
}

