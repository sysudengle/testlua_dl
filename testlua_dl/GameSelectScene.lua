--Game select scene
-- require "SceneManager"

function createGameSelectScene()
	local visibleSize = CCDirector:sharedDirector():getVisibleSize()

	local function createScene()
		print "3"
		local function createLayer()
			print "2"
			local function menuCallbackEnterGame()
				SceneManager:changeScene(GAME_RUN_SCENE_TYPE)
			end

			local function createMenu()
				print "1"
				local gameRunItem = CCMenuItemImage:create("button_game_start.png", "button_press.png")
        		gameRunItem:registerScriptTapHandler(menuCallbackEnterGame)
        		gameRunItem:setPosition(visibleSize.width / 2, visibleSize.height / 2)

        		print "1.1"
        		local menu = CCMenu:createWithItem(gameRunItem)
        		print "1.2"
        		print "1.3"
        		menu:setPosition(0, 0);

        		print "create menu"
        		return menu
			end

			local layer = GameSelectScene:create()
			local menu = createMenu()
			layer:addChild(menu)

			print "create layer"
			return layer
		end

		local scene = CCScene:create()
		local layer = createLayer()
		scene:addChild(layer)

		print "create scene"
		return scene
	end

	-- local gameScene = GameSelectScene:scene()
	local gameScene = createScene()
	return gameScene
end