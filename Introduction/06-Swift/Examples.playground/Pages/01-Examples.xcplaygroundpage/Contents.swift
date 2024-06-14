/*:
 # Higher Level Languages
 
 Languages like Swift are designed to keep your code concise and easy to work with, they achieve this by abstracting a lot of the common functionality that you will find yourself using across various projects such as strings and various data manipulation functions.
 
 > It is recommended to enable `Editor > Show Rendered Markup` so you can see this markup text with proper formatting and also to enable `Automatically Run` by force clicking the play bottom in the bottom left of the Xcode Playground window.
 
 You can view a higher level language to contain the CS50 library and much more to make your life easier. They are also commonly written more concisely for example in Swift you are able to omit semicolons and the `\n` escape sequence as you can see in the `print` statement below. You can also label parameters so the code becomes easier to read.
 
 Swift has something known as an interpreter, this means that even though it is a compiled language you can quickly run code from the command line without needing to compile it every time with the simple command `swift file.swift` this can save you a lot of time when iterating through versions of a project.
 
 This is the main benefit of working with higher level languages, **getting work done quicker**.
 
 * Callout(Tip):
 You can compile Swift code into a binary to ensure peak efficiency when running performance-critical tasks.
 */

print("Hello, world!")

/*:
 ## Memory Management
 
 If you define a variable you don't need to worry about specifying memory to allocate to it and then unallocating it once the variable is no longer in use as in higher level languages memory management is done automatically.
 */

var name = "World"
let a = 64 * 2
print("Hello, \(name)")
name = "Mac"
print("Hello, \(name)")
print("a is equal to \(a)")

/*:
 ## Blurring an Image
 
 Here is an example of the libraries you need already existing to save you the time of coding them all over again.
 
 > Sometimes it is worth coding a library that already exists, either to make it better, to include a feature that isn't within that library or to further your own personal programming knowledge.
 */

import SwiftUI
import PlaygroundSupport

struct ContentView: View {
  var body: some View {
    VStack {
      Text("Blurring an Image!").font(.title)
      Image(
        nsImage: #imageLiteral(resourceName: "sampleImage.jpg")
      ).blur(radius: 5.0)
    }
  }
}

PlaygroundPage.current.setLiveView(ContentView())

//: [Next](@next)
