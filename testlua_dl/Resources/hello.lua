require "Config"

-- for CCLuaEngine traceback
function __G__TRACKBACK__(msg)
    print("----------------------------------------")
    print("LUA ERROR: " .. tostring(msg) .. "\n")
    print(debug.traceback())
    print("----------------------------------------")
end

local function main()
    -- avoid memory leak
    collectgarbage("setpause", 100)
    collectgarbage("setstepmul", 5000)

    -- run
    require "SceneManager"
    SceneManager:changeScene(GAME_SELECT_SCENE_TYPE)
    -- SceneManager:sharedSceneManager():changeScene(0)
end

xpcall(main, __G__TRACKBACK__)
