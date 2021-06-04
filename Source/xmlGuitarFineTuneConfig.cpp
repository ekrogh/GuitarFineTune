/*
  ==============================================================================

	xmlGuitarFineTuneConfig.cpp
	Created: 8 May 2017 4:54:41pm
	Author:  eks

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "xmlGuitarFineTuneConfig.h"

//==============================================================================
xmlGuitarFineTuneConfig::xmlGuitarFineTuneConfig()
{
	if (!myXmlDir.isDirectory())
	{
		Result cdirRes = myXmlDir.createDirectory();
		if (!cdirRes.wasOk())
		{
			return;
		}
	}

	makeNewVerConfigFile();

}

xmlGuitarFineTuneConfig::~xmlGuitarFineTuneConfig()
{
	soundcontrol.release();
	displaycontrol.release();
	audiocontrol.release();
	guitarfinetuneconfig.reset(nullptr);
}

void xmlGuitarFineTuneConfig::makeNewVerConfigFile()
{
	std::unique_ptr<juce::XmlElement> oldGuitarfinetuneconfig;

	if (myXmlDir.getNumberOfChildFiles(juce::File::findFilesAndDirectories))
	{
		juce::String attributeValueString = "";

		// Find evt. old config files
//		for (DirectoryIterator di(myXmlDir, true); di.next();)
        for (DirectoryEntry di : RangedDirectoryIterator (myXmlDir, true))
        {
			oldGuitarfinetuneconfig = juce::XmlDocument::parse(di.getFile());

			// check we're looking at the right kind of document..
			if (oldGuitarfinetuneconfig->hasTagName("GUITARFINETUNECONFIG"))
			{
				// now we'll iterate its sub-elements looking for 'DISPLAYCONTROL' elements..
				for (auto* (e) : ((*oldGuitarfinetuneconfig).getChildIterator()))
				{
					if (e->hasTagName("SOUNDCONTROL"))
					{
						// found a DISPLAYCONTROL, so use some of its attributes..
						for (auto attriBute : soundControlAttributes)
						{
							if ((attributeValueString = e->getStringAttribute(attriBute.attributeName, "notFound")) != "notFound")
							{
								if (attriBute.value.isString())
									soundcontrol->setAttribute(attriBute.attributeName, attributeValueString);
								else if (attriBute.value.isInt())
									soundcontrol->setAttribute(attriBute.attributeName, e->getIntAttribute(attriBute.attributeName));
								else if (attriBute.value.isDouble())
									soundcontrol->setAttribute(attriBute.attributeName, e->getDoubleAttribute(attriBute.attributeName));
								else if (attriBute.value.isBool())
									soundcontrol->setAttribute(attriBute.attributeName, e->getBoolAttribute(attriBute.attributeName));
							}
						}
					}
					if (e->hasTagName("DISPLAYCONTROL"))
					{
						// found a DISPLAYCONTROL, so use some of its attributes..
						for (auto attriBute : displayControlAttributes)
						{
							if ((attributeValueString = e->getStringAttribute(attriBute.attributeName, "notFound")) != "notFound")
							{
								if (attriBute.value.isString())
									displaycontrol->setAttribute(attriBute.attributeName, attributeValueString);
								else if (attriBute.value.isInt())
									displaycontrol->setAttribute(attriBute.attributeName, e->getIntAttribute(attriBute.attributeName));
								else if (attriBute.value.isDouble())
									displaycontrol->setAttribute(attriBute.attributeName, e->getDoubleAttribute(attriBute.attributeName));
								else if (attriBute.value.isBool())
									displaycontrol->setAttribute(attriBute.attributeName, e->getBoolAttribute(attriBute.attributeName));
							}
						}
					}
					if (e->hasTagName("AUDIOCONTROL"))
					{
						// found a AUDIOCONTROL, so use some of its attributes..
						for (auto attriBute : audioControlAttributes)
						{
							if ((attributeValueString = e->getStringAttribute(attriBute.attributeName, "notFound")) != "notFound")
							{
								if (attriBute.value.isString())
									audiocontrol->setAttribute(attriBute.attributeName, attributeValueString);
								else if (attriBute.value.isInt())
									audiocontrol->setAttribute(attriBute.attributeName, e->getIntAttribute(attriBute.attributeName));
								else if (attriBute.value.isDouble())
									audiocontrol->setAttribute(attriBute.attributeName, e->getDoubleAttribute(attriBute.attributeName));
								else if (attriBute.value.isBool())
									audiocontrol->setAttribute(attriBute.attributeName, e->getBoolAttribute(attriBute.attributeName));
							}
						}
					}
				}
			}

			// Delete evt. old config files
			di.getFile().deleteFile();
		}
	}

	// Fill in the missing attributes
	for (auto attrName : soundControlAttributes)
	{
		if (soundcontrol->getStringAttribute(attrName.attributeName, "notFound") == "notFound")
		{
			if (attrName.value.isString())
				soundcontrol->setAttribute(attrName.attributeName, attrName.value.toString());
			else if (attrName.value.isInt())
				soundcontrol->setAttribute(attrName.attributeName, (int)attrName.value);
			else if (attrName.value.isDouble())
				soundcontrol->setAttribute(attrName.attributeName, (double)attrName.value);
			else if (attrName.value.isBool())
				soundcontrol->setAttribute(attrName.attributeName, (bool)attrName.value);
		}
	}

	for (auto attrName : displayControlAttributes)
	{
		if (displaycontrol->getStringAttribute(attrName.attributeName, "notFound") == "notFound")
		{
			if (attrName.value.isString())
				displaycontrol->setAttribute(attrName.attributeName, attrName.value.toString());
			else if (attrName.value.isInt())
				displaycontrol->setAttribute(attrName.attributeName, (int)attrName.value);
			else if (attrName.value.isDouble())
				displaycontrol->setAttribute(attrName.attributeName, (double)attrName.value);
			else if (attrName.value.isBool())
				displaycontrol->setAttribute(attrName.attributeName, (bool)attrName.value);
		}
	}

	for (auto attrName : audioControlAttributes)
	{
		if (audiocontrol->getStringAttribute(attrName.attributeName, "notFound") == "notFound")
		{
			if (attrName.value.isString())
				audiocontrol->setAttribute(attrName.attributeName, attrName.value.toString());
			else if (attrName.value.isInt())
				audiocontrol->setAttribute(attrName.attributeName, (int)attrName.value);
			else if (attrName.value.isDouble())
				audiocontrol->setAttribute(attrName.attributeName, (double)attrName.value);
			else if (attrName.value.isBool())
				audiocontrol->setAttribute(attrName.attributeName, (bool)attrName.value);
		}
	}

	// ..and add our new element to the parent node
	guitarfinetuneconfig->addChildElement(soundcontrol.get());
	guitarfinetuneconfig->addChildElement(displaycontrol.get());
	guitarfinetuneconfig->addChildElement(audiocontrol.get());
	//guitarfinetuneconfig->addChildElement(soundcontrol);
	//guitarfinetuneconfig->addChildElement(displaycontrol);
	//guitarfinetuneconfig->addChildElement(audiocontrol);
	xmlGuitarFineTuneConfig::writeConfigToXmlFile();
}

void xmlGuitarFineTuneConfig::writeConfigToXmlFile()
{
    guitarfinetuneconfig->writeTo(myXmlFile);
//	guitarfinetuneconfig->writeToFile(myXmlFile, String());
}
