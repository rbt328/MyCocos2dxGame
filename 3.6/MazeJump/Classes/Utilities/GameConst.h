#ifndef _Game_Const_h_
#define _Game_Const_h_

#include <string>


static const std::string USER_MAX_LEVEL = "MaxReachDifficultLevel";

static const std::string USER_LAST_LEVEL = "LastReachDifficultLevel";

static const std::string USER_HEART_NUM = "UserHeartNum";

static const std::string USER_GOLD_NUM = "UserGoldNum";

static const std::string USER_ROLE_DATA  = "UserRoleData";

static const std::string USER_DEFAULT_ROLE_ID = "UserDefaultRoleID";

///Font
static std::string FONT_FXZS = "comic_sans_ms.ttf";


//UI

static const int LAYER_WHITE = 3;

static const std::string LAYER_NAME_UI = "UILayer";
static const int LAYER_UI = 0;


static const std::string LAYER_NAME_MASK = "MaskLayer";
static const int LAYER_MASK = 1;


static const std::string LAYER_NAME_DIALOG = "UIDialogLayer";
static const int LAYER_DIALOG = 2;





////Event
static const std::string EVENT_GAME_PAUSE = "GAME_PAUSE";
static const std::string EVENT_GOLD_CHANGE = "GOLD_CHANGE";
static const std::string EVENT_HEART_CHANGE = "HEART_CHANGE";
static const std::string EVENT_MAX_DISTANCE_CHANGE = "MAX_DISTANCE_CHANGE";
static const std::string EVENT_RAINBOW_VALUE_CHANGE = "RAINBOW_VALUE_CHANGE";
static const std::string EVENT_RUNNER_LOSE = "RUNNER_LOSE";
static const std::string EVENT_RUNNER_LOSE_CHANGE_VIEW = "RUNNER_LOSE_CHANGE_VIEW";
static const std::string EVENT_RUNNER_RECOVER_PAUSE = "RUNNER_RECOVER_PAUSE";
static const std::string EVENT_RUNNER_PAUSE_RESUME = "RUNNER_PAUSE_RESUME";
static const std::string EVENT_MAZEJUMP_WIN = "MAZEJUMP_WIN";
static const std::string EVENT_MAZEJUMP_LOSE = "MAZEJUMP_LOSE";
static const std::string EVENT_MAZEJUMP_RECORD_END = "MAZEJUMP_RECORD_END";
static const std::string EVENT_START_GOLD_CHANGE = "START_GOLD_CHANGE";
static const std::string EVENT_START_HEART_CHANGE = "START_HEART_CHANGE";
static const std::string EVENT_CHARACTER_MODEL_CHANGE = "CHARACTER_MODEL_CHANGE";
#endif //_Scene_Const_h_