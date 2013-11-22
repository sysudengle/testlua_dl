--Game run scene
-- require "Config"

function createGameRunScene()
	local scene = GameRunScene:create()

	local function loadResourceToCache()
		CCSpriteFrameCache:sharedSpriteFrameCache():addSpriteFramesWithFile(SHOOT_BACKGROUND_PLIST);
    	CCSpriteFrameCache:sharedSpriteFrameCache():addSpriteFramesWithFile(SHOOT_PLIST);
	end
	local function createMenuLayer()
		local menuLayer = MenuLayer:create(scene)
		return menuLayer
	end

	local function createTouchLayer()
		local touchLayer = TouchLayer:create(scene)
		return touchLayer
	end

	local function createSpriteLayer()
		local spriteLayer = SpriteLayer:create(scene)

		local function createHeroManager()
			local heroManager = PlayerManager:create(spriteLayer, 2)
			-- local function createHero()
				-- local hero = Player:createFromJsonFile(0)
			-- end
			return heroManager
		end

		local function createBounsManager()
			print "suck !1"
			local bonusManager = BonusManager:create(spriteLayer)
			print "suck !"
			return bonusManager
		end

		local function createBulletManager()
			local bulletManager = BulletManager:create(spriteLayer, 1)

			return bulletManager
		end

		local function createEnemyManager()
			local enemyManager = EnemyManager:create(spriteLayer, 1)

			return enemyManager
		end

		local heroManager = createHeroManager()
		local bulletManager = createBulletManager()
		local enemyManager = createEnemyManager()
		local bonusManager = createBounsManager()

		spriteLayer:setPlayerManager(heroManager)
		spriteLayer:setBulletManager(bulletManager)
		spriteLayer:setEnemyManager(enemyManager)
		spriteLayer:setBonusManager(bonusManager)

		spriteLayer:addChild(bulletManager, 1)
		spriteLayer:addChild(heroManager, 2)
		spriteLayer:addChild(enemyManager, 3)
		spriteLayer:addChild(bonusManager, 4)

		return spriteLayer
	end

	local function createBackgroundLayer()
		local backgroundLayer = BackgroundLayer:create(scene)

		return backgroundLayer
	end

	-- load resource
	loadResourceToCache()
	
	-- add layers
	local backgroundLayer = createBackgroundLayer()
	local spriteLayer = createSpriteLayer()
	local touchLayer = createTouchLayer()
	local menuLayer = createMenuLayer()

	-- set touch delegate
	touchLayer:setDelegate(spriteLayer)

	scene:setBackgroundLayer(backgroundLayer)
	scene:setSpriteLayer(spriteLayer)
	scene:setTouchLayer(touchLayer)
	scene:setMenuLayer(menuLayer)

	scene:addChild(backgroundLayer)
	scene:addChild(spriteLayer)
	scene:addChild(touchLayer)
	scene:addChild(menuLayer)

	return scene
end