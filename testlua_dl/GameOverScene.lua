function createGameOverScene(data)
	local function createScene(data)
		local gameScene = GameOverScene:create(data)

		return gameScene
	end
	local gameScene = createScene(data)
	print "game over create"

	return gameScene
end