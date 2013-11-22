require "GameSelectScene"
require "GameRunScene"
require "GameOverScene"

SceneManager = {
	changeScene = function(self, sceneType, data)
		local newScene = nil

		if sceneType == GAME_SELECT_SCENE_TYPE then
			print "select"
			newScene = createGameSelectScene()
		elseif sceneType == GAME_RUN_SCENE_TYPE then
			print "enter game"
			newScene = createGameRunScene()
		elseif sceneType == GAME_OVER_SCENE_TYPE then
			print "game over"
			newScene = createGameOverScene(data)
		elseif sceneType == GAME_WIN_SCENE_TYPE then

		end

		if newScene == nil then
			return
		end

		local director = CCDirector:sharedDirector()
		local runningScene = director:getRunningScene()

		if runningScene == nil then
			print "run scene"
			director:runWithScene(newScene)
		else
			director:replaceScene(newScene)
		end
	end
}

gameOverScene = function(score)
	print "shit"
	SceneManager:changeScene(GAME_OVER_SCENE_TYPE, score)
end

test = function()
	print "test"
end

gameRunScene = function()
	SceneManager:changeScene(GAME_RUN_SCENE_TYPE)
end