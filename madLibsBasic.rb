#This is my very first project using the language Ruby!
#Please be nice...

    loop do

puts "Welcome to MadLibs on Rails ;)"
puts "You'll be prompted to input different types of word to fill out a story!"

print "Please enter a plural noun: "
plural_noun = gets.chomp()

print "Please enter another plural noun: "
plural_noun2 = gets.chomp()

print "Enter a celebirty of your choosing: "
celebirty = gets.chomp()

print "Enter a verb: "
verb = gets.chomp()

print "Enter an adverb: "
adverb = gets.chomp()

print "Enter an adjective: "
adjective = gets.chomp()

story = <<~STORY

  🌟 Today was the big day at the Annual #{plural_noun.capitalize} Expo! 🌟

  Crowds of eager #{plural_noun} filled the grand hall, all waiting for the surprise guest: none other than #{celebirty}!
  With a deep breath, #{celebirty} stepped onto the stage and declared, "I'm going to #{verb} #{adverb} right now!"
  The audience gasped—and then erupted into applause when #{celebirty} performed the most #{adjective} feat anyone had ever seen.
  Meanwhile, backstage, a troupe of #{plural_noun2} practiced their dance routine, hoping to upstage the star.
  In the end, there was enough excitement to last until next year’s expo—and plenty of #{plural_noun2} to tell the tale.

STORY

puts story


    print "Do you want to play again? (y/n): "
    answer = gets.chomp.strip.downcase

    until %w[y n].include?(answer)
        print "Invalid input. Please enter 'y' or 'n': "
        answer = gets.chomp.strip.downcase
end

    break if answer == 'n'
        puts "Thanks for playing!"

end

