#include "main.h"
FormatHandler handlers[] = {
	{'s', handle_string},
	{'c', handle_char},
	{'d', handle_integer},
	{'i', handle_integer},
	{'b', handle_binary},
	{'u', handle_unsigned},
	{'o', handle_octal},
	{'x', handle_hex_lower},
	{'X', handle_hex_upper},
	{0, NULL}
};
