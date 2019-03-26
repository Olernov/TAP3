#define TL_OK					0		// загрузка прошла успешно
#define TL_PARAM_ERROR			-1		// ошибка передачи параметров (имени файла и ID)
#define TL_FILEERROR			-2		// ошибка чтения исходного файла
#define TL_DECODEERROR			-3		// ошибка декодирования ASN
#define TL_NOTIFICATION			-4		// файл-уведомление
#define TL_CONNECTERROR			-5		// ошибка коннекта к базе
#define TL_MISSINGSTRUCT		-6		// отсутствует обязательная структура (mandatory)
#define TL_ORACLEERROR			-7		// ошибка работы с базой, см. err-файл
#define TL_NEWCOMPONENT			-8		// файл содержит компоненты, не обрабатываемые парсером
#define TL_AUDITFAULT			-9		// расхождение реальных начислений либо кол-ва звонков с указанными в Audit Control Info
#define TL_WRONGCODE			-10		// ссылка не несуществующий UTC offset, Exchange Rate или Recording Entity
#define TL_TAP_NOT_VALIDATED	-11		// невозможно провести валидацию файла
#define TL_UNKNOWN				-999		// неизвестная ошибка (исключение)

// типы сообщений лога
#define LOG_INFO			0
#define LOG_WARNING			1
#define LOG_ERROR			3

// file statuses in DB
#define INFILE_STATUS_NEW					0
#define INFILE_LOADED_FOR_CHARGING			5
#define INFILE_STATUS_FATAL					-80
#define INFILE_STATUS_UNABLE_TO_VALIDATE	-10
#define INFILE_STATUS_UNKNOWN_ERROR			-999
#define OUTFILE_IN_PROGRESS					10
#define OUTFILE_READY_FOR_SENDING			20
#define OUTFILE_CREATED_AND_SENT			30

#define INRAP_READY_TO_SEND_ACK				3
#define INRAP_ACK_SENT						7
#define OUTRAP_ACKNOWLEDGE_RECEIVED			45




