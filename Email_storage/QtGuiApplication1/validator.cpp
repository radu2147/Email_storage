#include "validator.h"

void Validator::validate(const Email& ot)
{
	if (ot.get_email().size() == 0) throw exception("Cont incorect");
	if (ot.get_pass().size() == 0) throw  exception("Parola incorecta");
	if (ot.get_plat().size() == 0) throw  exception("Platforma incorecta");
}

void ValidUser::validate(const string& us)
{
	if (us.size() == 0) throw exception("ESGe");
}
